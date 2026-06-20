_QWORD *__fastcall sde_encoder_phys_vid_underrun_irq(_QWORD *result)
{
  _DWORD *v1; // x8
  _QWORD *v2; // x1
  __int64 v3; // x0

  if ( result )
  {
    v1 = (_DWORD *)result[48];
    v2 = result;
    if ( v1 )
    {
      v3 = *result;
      if ( *(v1 - 1) != 468003652 )
        __break(0x8228u);
      return (_QWORD *)((__int64 (__fastcall *)(__int64, _QWORD *))v1)(v3, v2);
    }
  }
  return result;
}
