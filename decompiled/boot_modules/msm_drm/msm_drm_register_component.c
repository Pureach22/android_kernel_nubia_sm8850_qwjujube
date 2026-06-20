__int64 __fastcall msm_drm_register_component(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  if ( a1 && (v2 = *(_QWORD *)(a1 + 56)) != 0 )
    return blocking_notifier_chain_register(v2 + 5840, a2);
  else
    return 4294967274LL;
}
