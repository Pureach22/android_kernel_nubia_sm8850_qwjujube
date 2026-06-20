__int64 __fastcall ieee80211_get_tx_power(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x29
  __int64 (__fastcall *v4)(__int64, __int64); // x8
  __int64 v5; // x0
  __int64 v6; // x1
  int *v8; // x8
  int v9; // w8

  if ( a1 )
  {
    v4 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 2000) + 720LL);
    if ( v4 )
    {
      v5 = a1 + 1536;
      v6 = a2 + 4704;
      if ( *((_DWORD *)v4 - 1) != -817409229 )
        __break(0x8228u);
      return v4(v5, v6);
    }
    else
    {
      if ( *(_BYTE *)(a1 + 2936) )
        v8 = (int *)(a1 + 1540);
      else
        v8 = (int *)(a2 + 5020);
      v9 = *v8;
      *a3 = v9;
      if ( v9 == 0x80000000 )
        return 4294967274LL;
      else
        return 0;
    }
  }
  else
  {
    __break(0x800u);
    preempt_schedule_notrace(0);
    return *(unsigned int *)(v3 + 28);
  }
}
