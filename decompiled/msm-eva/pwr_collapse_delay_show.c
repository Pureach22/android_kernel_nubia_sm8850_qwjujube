__int64 __fastcall pwr_collapse_delay_show(int a1, int a2, char *s)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(cvp_driver + 48);
  if ( v3 )
    return snprintf(s, 0x1000u, "%u\n", *(_DWORD *)(v3 + 1040));
  else
    return -22;
}
