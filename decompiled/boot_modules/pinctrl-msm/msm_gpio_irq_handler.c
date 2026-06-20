__int64 __fastcall msm_gpio_irq_handler(__int64 a1)
{
  __int64 v1; // x20
  __int64 data; // x0
  _QWORD *v4; // x23
  __int64 v5; // x21
  void (__fastcall *v6)(_QWORD); // x8
  void (__fastcall *v7)(_QWORD); // x8
  int v8; // w24
  signed int i; // w8
  int next_bit; // w0
  unsigned int v11; // w22
  __int64 v12; // x27
  __int64 (__fastcall *v13)(_QWORD); // x8

  v1 = *(_QWORD *)(a1 + 8);
  data = gpiochip_get_data(v1);
  v4 = *(_QWORD **)(a1 + 72);
  v5 = data;
  if ( !v4[9] )
  {
    v6 = (void (__fastcall *)(_QWORD))v4[7];
    if ( v6 )
      goto LABEL_6;
    v7 = (void (__fastcall *)(_QWORD))v4[6];
    if ( *((_DWORD *)v7 - 1) != 270158662 )
      __break(0x8228u);
    v7(a1 + 48);
    v6 = (void (__fastcall *)(_QWORD))v4[5];
    if ( v6 )
    {
LABEL_6:
      if ( *((_DWORD *)v6 - 1) != 270158662 )
        __break(0x8228u);
      v6(a1 + 48);
    }
  }
  v8 = 0;
  for ( i = 0; ; i = v11 + 1 )
  {
    next_bit = find_next_bit(v5 + 808, *(unsigned __int16 *)(v5 + 188), i);
    v11 = next_bit;
    if ( next_bit >= *(unsigned __int16 *)(v5 + 188) )
      break;
    v12 = *(_QWORD *)(*(_QWORD *)(v5 + 968) + 32LL) + 112LL * next_bit;
    if ( (((unsigned __int64)(unsigned int)readl((unsigned int *)(*(_QWORD *)(v5
                                                                            + 976
                                                                            + 8 * ((*(_QWORD *)(v12 + 84) >> 5) & 3LL))
                                                                + *(unsigned int *)(v12 + 72))) >> (*(_QWORD *)(v12 + 92)
                                                                                                  & 0x1F))
        & 1) != 0 )
    {
      generic_handle_domain_irq(*(_QWORD *)(v1 + 296), v11);
      ++v8;
    }
  }
  if ( v8 )
  {
    v13 = (__int64 (__fastcall *)(_QWORD))v4[9];
    if ( v13 )
      goto LABEL_16;
  }
  else
  {
    handle_bad_irq(a1);
    v13 = (__int64 (__fastcall *)(_QWORD))v4[9];
    if ( v13 )
      goto LABEL_16;
  }
  v13 = (__int64 (__fastcall *)(_QWORD))v4[8];
LABEL_16:
  if ( *((_DWORD *)v13 - 1) != 270158662 )
    __break(0x8228u);
  return v13(a1 + 48);
}
