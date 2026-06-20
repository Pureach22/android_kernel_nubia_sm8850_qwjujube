__int64 __fastcall msm_gpio_dirconn_handler(__int64 result)
{
  __int64 v1; // x21
  _QWORD *v2; // x20
  __int64 v3; // x19
  void (__fastcall *v4)(_QWORD); // x8
  void (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x0
  void (__fastcall *v7)(_QWORD); // x8

  v1 = *(_QWORD *)(result + 8);
  if ( v1 )
  {
    v2 = *(_QWORD **)(result + 72);
    v3 = result;
    if ( !v2[9] )
    {
      v4 = (void (__fastcall *)(_QWORD))v2[7];
      if ( v4 )
        goto LABEL_7;
      v5 = (void (__fastcall *)(_QWORD))v2[6];
      v6 = result + 48;
      if ( *((_DWORD *)v5 - 1) != 270158662 )
        __break(0x8228u);
      v5(v6);
      v4 = (void (__fastcall *)(_QWORD))v2[5];
      if ( v4 )
      {
LABEL_7:
        if ( *((_DWORD *)v4 - 1) != 270158662 )
          __break(0x8228u);
        v4(v3 + 48);
      }
    }
    generic_handle_irq(*(unsigned int *)(v1 + 4));
    v7 = (void (__fastcall *)(_QWORD))v2[9];
    if ( !v7 )
      v7 = (void (__fastcall *)(_QWORD))v2[8];
    if ( *((_DWORD *)v7 - 1) != 270158662 )
      __break(0x8228u);
    v7(v3 + 48);
    return irq_set_irqchip_state(*(unsigned int *)(v3 + 52), 1, 0);
  }
  return result;
}
