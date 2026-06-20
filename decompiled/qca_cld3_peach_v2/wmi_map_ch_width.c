__int64 __fastcall wmi_map_ch_width(unsigned int a1)
{
  if ( a1 > 9 )
    return 8;
  else
    return dword_AD8FB0[a1];
}
