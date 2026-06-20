__int64 __fastcall cfg80211_set_monitor_channel(_DWORD *a1)
{
  int v1; // w9
  unsigned int v2; // w8
  __int64 v3; // x8
  _DWORD *v4; // x0
  unsigned int (__fastcall *v5)(_QWORD); // x8

  if ( *(_QWORD *)(*(_QWORD *)a1 + 312LL) )
  {
    v1 = a1[41];
    v2 = -16;
    if ( v1 >= 1 && v1 == a1[42] )
    {
      v3 = *(_QWORD *)a1;
      v4 = a1 + 248;
      v5 = *(unsigned int (__fastcall **)(_QWORD))(v3 + 312);
      if ( *((_DWORD *)v5 - 1) != 699476211 )
        __break(0x8228u);
      return v5(v4);
    }
  }
  else
  {
    return (unsigned int)-95;
  }
  return v2;
}
