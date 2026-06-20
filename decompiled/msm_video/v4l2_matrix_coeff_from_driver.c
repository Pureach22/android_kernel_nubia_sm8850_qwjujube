__int64 __fastcall v4l2_matrix_coeff_from_driver(__int64 result, unsigned int a2, __int64 a3)
{
  __int64 v3; // x9
  __int64 v4; // x8
  _DWORD *v5; // x9

  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 320) + 3912LL) + 336LL);
  v4 = *(unsigned int *)(v3 + 72);
  if ( (_DWORD)v4 )
  {
    v5 = (_DWORD *)(*(_QWORD *)(v3 + 64) + 4LL);
    while ( *v5 != a2 )
    {
      --v4;
      v5 += 2;
      if ( !v4 )
        goto LABEL_5;
    }
    return (unsigned int)*(v5 - 1);
  }
  else
  {
LABEL_5:
    if ( result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8CB12, "err ", result + 340, a3, a2);
      return 0;
    }
  }
  return result;
}
