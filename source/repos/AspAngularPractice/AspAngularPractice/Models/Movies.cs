using System;
using System.Collections.Generic;
using System.Linq;
using System.ComponentModel.DataAnnotations;

namespace AspAngularPractice.Models
{
    public class Movies
    {
        public Movies(int id, string movieName, string movieGender)
        {
            this.id = id;
            this.movieName = movieName;
            this.movieGender = movieGender;
        }

        [Key]
        public int id { get; set; }
        public string movieName { get; set; }
        public string movieGender { get; set; }
    }
}
