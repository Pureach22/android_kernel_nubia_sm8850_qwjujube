__int64 __fastcall msm_drm_unregister_component(__int64 a1)
{
  __int64 v1; // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 56)) != 0 )
    return blocking_notifier_chain_unregister(v1 + 5840);
  else
    return 4294967274LL;
}
