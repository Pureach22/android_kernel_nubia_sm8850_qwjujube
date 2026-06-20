__int64 __fastcall aw882xx_spin_value_get(__int64 a1, _DWORD *a2, char a3)
{
  if ( (g_spin_mode & 0xFFFFFFFE) == 2 || (a3 & 1) == 0 )
  {
    *a2 = g_spin_value;
    return 0;
  }
  else if ( g_spin_mode == 1 )
  {
    return aw882xx_dsp_read_spin(a2);
  }
  else
  {
    return 0;
  }
}
