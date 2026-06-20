__int64 __fastcall reg_get_eirp_pwr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        char a7,
        unsigned int a8,
        char a9)
{
  if ( a5 == 1 )
    return (unsigned int)(char)((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD))reg_get_eirp_from_mas_chan_list)(
                                 a1,
                                 a2,
                                 a4,
                                 1,
                                 a7 & 1,
                                 a8,
                                 a9 & 1);
  else
    return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))reg_get_eirp_from_mas_chan_list)(
             a1,
             a2,
             a4,
             a5,
             a7 & 1,
             a8,
             a9 & 1);
}
