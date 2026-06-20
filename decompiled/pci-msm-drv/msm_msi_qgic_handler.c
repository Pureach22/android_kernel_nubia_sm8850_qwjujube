__int64 __fastcall msm_msi_qgic_handler(__int64 a1)
{
  _QWORD *v2; // x20
  void (__fastcall *v3)(_QWORD); // x8
  void (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x1
  __int64 v8; // x0
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 result; // x0
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 72);
  if ( !v2[9] )
  {
    v3 = (void (__fastcall *)(_QWORD))v2[7];
    if ( v3 )
      goto LABEL_6;
    v4 = (void (__fastcall *)(_QWORD))v2[6];
    v5 = a1 + 48;
    if ( *((_DWORD *)v4 - 1) != 270158662 )
      __break(0x8228u);
    v4(v5);
    v3 = (void (__fastcall *)(_QWORD))v2[5];
    if ( v3 )
    {
LABEL_6:
      if ( *((_DWORD *)v3 - 1) != 270158662 )
        __break(0x8228u);
      v3(a1 + 48);
    }
  }
  v6 = *(_QWORD *)(a1 + 8);
  v7 = *(unsigned int *)(a1 + 52);
  v11 = 0;
  if ( _irq_resolve_mapping(*(_QWORD *)(v6 + 112), v7, &v11) )
    v8 = v11;
  else
    v8 = 0;
  generic_handle_irq(v8);
  v9 = (__int64 (__fastcall *)(_QWORD))v2[9];
  if ( !v9 )
    v9 = (__int64 (__fastcall *)(_QWORD))v2[8];
  if ( *((_DWORD *)v9 - 1) != 270158662 )
    __break(0x8228u);
  result = v9(a1 + 48);
  _ReadStatusReg(SP_EL0);
  return result;
}
