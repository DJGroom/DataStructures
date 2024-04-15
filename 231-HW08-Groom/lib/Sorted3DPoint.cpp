#include "Sorted3DPoint.hpp"

        std::ostream &operator<<(std::ostream& os, const Sorted3Dpoint& ob)
        {
            os << std::endl << "Name: " << ob.name << std::endl << "XYZ: " << ob.x << " " << ob.y << " " << ob.z << " " << std::endl;
            return os;
        };
        Sorted3Dpoint::Sorted3Dpoint(std::string iname, double ix, double iy, double iz)
        {
            name = iname;
            x = ix;
            y = iy;
            z = iz;
        };
        Sorted3Dpoint::Sorted3Dpoint()
        {
            name = "none";
            x = 0.00;
            y = 0.00;
            z = 0.00;
        };
        void Sorted3Dpoint::SetName(std::string iname)
        {
            name = iname;
        };
        std::string Sorted3Dpoint::GetName()
        {
            return name;
        };
        void Sorted3Dpoint::SetXYZ(double ix, double iy, double iz)
        {
            x = ix;
            y = iy;
            z = iz;
        };
        std::vector<double> Sorted3Dpoint::GetXYZ()
        {
            std::vector<double> xyz;
            xyz.push_back(x);
            xyz.push_back(y);
            xyz.push_back(z);
            return xyz;
        };
        std::string& Sorted3Dpoint::ToString(std::string &s) const
        {
            std::stringstream for_double_ss;
            double tempx = x;
            double tempy = y;
            double tempz = z;
            
            std::cout << std::to_string(x) << std::endl;
            
            //std::cout << "so we work3";
            for_double_ss << "Name: " << name << std::endl;
            for_double_ss << "X: " << std::setprecision(3) << x;
            for_double_ss << "Y: " << std::setprecision(3) << y;
            for_double_ss << "Z: " << std::setprecision(3) << z;

            s.append(for_double_ss.str());
            return s;
        };
        bool Sorted3Dpoint::operator==(Sorted3Dpoint const &ob2)
        {
            if(CompareToMyself(ob2) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        };
        bool Sorted3Dpoint::operator>(Sorted3Dpoint const &ob2)
        {
            if(CompareToMyself(ob2) > 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        };
        bool Sorted3Dpoint::operator>=(Sorted3Dpoint const &ob2)
        {
            if(CompareToMyself(ob2) >= 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        };
        bool Sorted3Dpoint::operator<(Sorted3Dpoint const &ob2)
        {
            if(CompareToMyself(ob2) < 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        };
        bool Sorted3Dpoint::operator<=(Sorted3Dpoint const &ob2)
        {
            if(CompareToMyself(ob2) <= 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        };