__int64 __fastcall mlo_mgr_num_roam_links(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x8

  v1 = *(_QWORD *)(a1 + 1360);
  if ( !v1 )
    return 1;
  v2 = *(_QWORD *)(v1 + 2224);
  if ( v2 && (v3 = *(_QWORD *)(v2 + 288)) != 0 && (v4 = *(_QWORD *)(v3 + 144)) != 0 )
    return *(unsigned __int8 *)(v4 + 1);
  else
    return 0;
}
