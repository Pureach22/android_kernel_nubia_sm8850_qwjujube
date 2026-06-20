__int64 __fastcall cam_icp_v2_cpas_unregister(__int64 a1)
{
  if ( a1 )
    return cam_cpas_unregister_client(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 112) + 3680LL) + 44LL));
  else
    return 4294967274LL;
}
