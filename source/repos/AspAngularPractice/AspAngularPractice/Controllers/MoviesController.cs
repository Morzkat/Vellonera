using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using AspAngularPractice.Models;

namespace AspAngularPractice.Controllers
{
    [Produces("application/json")]
    [Route("api/Movies")]
    public class MoviesController : Controller
    {
        private readonly MoviesContext _context;

        public MoviesController(MoviesContext context)
        {
            _context = context;
        }

        // GET: api/Movies
        [HttpGet]
        public IEnumerable<Movies> Getmovies()
        {
            return _context.movies;
        }

        // GET: api/Movies/5
        [HttpGet("{id}")]
        public async Task<IActionResult> GetMovies([FromRoute] int id)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            var movies = await _context.movies.SingleOrDefaultAsync(m => m.id == id);

            if (movies == null)
            {
                return NotFound();
            }

            return Ok(movies);
        }

        // PUT: api/Movies/5
        [HttpPut("{id}")]
        public async Task<IActionResult> PutMovies([FromRoute] int id, [FromBody] Movies movies)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            if (id != movies.id)
            {
                return BadRequest();
            }

            _context.Entry(movies).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!MoviesExists(id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return NoContent();
        }

        // POST: api/Movies
        [HttpPost]
        public async Task<IActionResult> PostMovies([FromBody] Movies movies)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            _context.movies.Add(movies);
            await _context.SaveChangesAsync();

            return CreatedAtAction("GetMovies", new { id = movies.id }, movies);
        }

        // DELETE: api/Movies/5
        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteMovies([FromRoute] int id)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            var movies = await _context.movies.SingleOrDefaultAsync(m => m.id == id);
            if (movies == null)
            {
                return NotFound();
            }

            _context.movies.Remove(movies);
            await _context.SaveChangesAsync();

            return Ok(movies);
        }

        private bool MoviesExists(int id)
        {
            return _context.movies.Any(e => e.id == id);
        }
    }
}