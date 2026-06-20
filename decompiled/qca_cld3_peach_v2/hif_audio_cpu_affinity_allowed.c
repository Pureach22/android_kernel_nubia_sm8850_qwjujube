__int64 __fastcall hif_audio_cpu_affinity_allowed(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 v7; // kr00_8
  unsigned __int64 v8; // x9
  __int64 result; // x0
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = a3;
  if ( (qdf_cpumask_equal(v10, a2 + 16) & 1) != 0 )
    goto LABEL_6;
  v7 = a4 - *(_QWORD *)(a2 + 32);
  v8 = 10 * v7 / 0xC0;
  if ( 10 * v7 < v7 )
    v8 = 10 * (v7 / 0xC0);
  if ( v8 >= *(_QWORD *)(a1 + 4200) )
LABEL_6:
    result = 1;
  else
    result = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
