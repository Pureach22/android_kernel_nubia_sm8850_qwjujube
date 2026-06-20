__int64 __fastcall wcd939x_clsh_dummy(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x0

  if ( (a3 & 0xC) == 0 )
    return 0;
  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) - 184LL) + 152LL) + 40LL);
  return swr_slvdev_datapath_control(v3, *(unsigned __int8 *)(v3 + 64), 0);
}
