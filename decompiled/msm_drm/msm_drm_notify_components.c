__int64 __fastcall msm_drm_notify_components(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8

  if ( a1 && (v2 = *(_QWORD *)(a1 + 56)) != 0 )
    return blocking_notifier_call_chain(v2 + 5840, a2);
  else
    return 4294967274LL;
}
