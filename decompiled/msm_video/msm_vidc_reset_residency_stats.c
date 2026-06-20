__int64 __fastcall msm_vidc_reset_residency_stats(__int64 a1)
{
  __int64 v2; // x8
  __int64 (__fastcall *v3)(_QWORD); // x8
  unsigned int v4; // w20

  mutex_lock(a1 + 3856);
  if ( a1 && (v2 = *(_QWORD *)(a1 + 6552)) != 0 && (v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 144)) != nullptr )
  {
    if ( *((_DWORD *)v3 - 1) != -1850880742 )
      __break(0x8228u);
    v4 = v3(a1);
  }
  else
  {
    v4 = 0;
  }
  mutex_unlock(a1 + 3856);
  return v4;
}
