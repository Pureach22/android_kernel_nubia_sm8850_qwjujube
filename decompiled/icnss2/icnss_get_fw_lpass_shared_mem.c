__int64 __fastcall icnss_get_fw_lpass_shared_mem(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 v3; // x8
  __int64 v4; // x9

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
    return 4294967274LL;
  v4 = *(_QWORD *)(v3 + 6160);
  if ( !v4 )
    return 4294967274LL;
  *a2 = v4;
  *a3 = *(_QWORD *)(v3 + 6168);
  return 0;
}
