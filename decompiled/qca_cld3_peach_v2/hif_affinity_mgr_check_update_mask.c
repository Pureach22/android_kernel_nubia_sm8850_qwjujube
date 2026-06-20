__int64 __fastcall hif_affinity_mgr_check_update_mask(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4, __int64 a5)
{
  __int64 result; // x0
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v11[0] = a3;
  if ( (qdf_cpumask_empty(v11) & 1) == 0 )
  {
    if ( (hif_audio_cpu_affinity_allowed(a1, a2, v11[0], a5) & 1) == 0 && *(_BYTE *)(a2 + 40) != 1 )
    {
      result = 3;
      goto LABEL_4;
    }
    qdf_cpumask_and(&v10, a1 + 26384, v11);
    if ( (*a4 & (unsigned int)v10) == 0 )
      goto LABEL_3;
    qdf_cpumask_andnot(a4, a2 + 8, &v10);
    if ( (qdf_cpumask_empty(a4) & 1) != 0 )
      qdf_cpumask_complement(a4, &v10);
LABEL_11:
    result = 0;
    goto LABEL_4;
  }
  if ( (qdf_cpumask_equal(a4, a2 + 8) & 1) == 0 )
  {
    qdf_cpumask_copy(a4, a2 + 8);
    goto LABEL_11;
  }
LABEL_3:
  result = 6;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
