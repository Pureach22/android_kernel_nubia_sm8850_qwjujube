_QWORD *__fastcall msm_vidc_get_fence_from_id(__int64 a1, _QWORD *a2, __int64 a3)
{
  _QWORD *v3; // x8

  if ( !a2 )
    return nullptr;
  v3 = a2;
  while ( 1 )
  {
    v3 = (_QWORD *)*v3;
    if ( v3 == a2 )
      break;
    if ( v3[20] == a3 )
      return v3;
  }
  if ( a1 )
  {
    if ( (msm_vidc_debug & 4) != 0 )
      printk(&unk_97882, "low ", a1 + 340, "msm_vidc_get_fence_from_id", a3);
  }
  return nullptr;
}
