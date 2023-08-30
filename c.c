using System;

namespace ComplexExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to the Complex Example!");

            ComplexNumber complex1 = new ComplexNumber(3, 4);
            Console.WriteLine($"Complex Number 1: {complex1}");

            ComplexNumber complex2 = new ComplexNumber(1, 2);
            Console.WriteLine($"Complex Number 2: {complex2}");

            ComplexNumber sum = complex1 + complex2;
            Console.WriteLine($"Sum: {sum}");

            ComplexNumber difference = complex1 - complex2;
            Console.WriteLine($"Difference: {difference}");

            ComplexNumber product = complex1 * complex2;
            Console.WriteLine($"Product: {product}");

            Console.WriteLine($"Magnitude of Complex Number 1: {complex1.Magnitude}");

            Console.WriteLine("Thank you for exploring the Complex Example!");
        }
    }

    class ComplexNumber
    {
        public double Real { get; }
        public double Imaginary { get; }

        public ComplexNumber(double real, double imaginary)
        {
            Real = real;
            Imaginary = imaginary;
        }

        public static ComplexNumber operator +(ComplexNumber a, ComplexNumber b)
        {
            double real = a.Real + b.Real;
            double imaginary = a.Imaginary + b.Imaginary;
            return new ComplexNumber(real, imaginary);
        }

        public static ComplexNumber operator -(ComplexNumber a, ComplexNumber b)
        {
            double real = a.Real - b.Real;
            double imaginary = a.Imaginary - b.Imaginary;
            return new ComplexNumber(real, imaginary);
        }

        public static ComplexNumber operator *(ComplexNumber a, ComplexNumber b)
        {
            double real = (a.Real * b.Real) - (a.Imaginary * b.Imaginary);
            double imaginary = (a.Real * b.Imaginary) + (a.Imaginary * b.Real);
            return new ComplexNumber(real, imaginary);
        }

        public double Magnitude
        {
            get { return Math.Sqrt(Real * Real + Imaginary * Imaginary); }
        }

        public override string ToString()
        {
            return $"({Real} + {Imaginary}i)";
        }
    }
}
