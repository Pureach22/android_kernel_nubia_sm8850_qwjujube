_QWORD *__fastcall msm_vidc_get_context_bank_for_device(__int64 a1, __int64 *a2)
{
  __int64 v2; // x8
  _QWORD *v4; // x20
  __int64 v7; // x4

  v2 = *(_QWORD *)(a1 + 3904);
  v4 = *(_QWORD **)(v2 + 112);
  if ( v4 >= &v4[7 * *(unsigned int *)(v2 + 120)] )
    goto LABEL_6;
  while ( !(unsigned int)of_device_is_compatible(a2[93], *v4) )
  {
    v4 += 7;
    if ( (unsigned __int64)v4 >= *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 112LL)
                               + 56 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 3904) + 120LL) )
      goto LABEL_6;
  }
  if ( !v4 )
  {
LABEL_6:
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v7 = a2[14];
      if ( !v7 )
        v7 = *a2;
      printk(&unk_86AB4, "err ", 0xFFFFFFFFLL, "codec", v7);
    }
    return nullptr;
  }
  return v4;
}
