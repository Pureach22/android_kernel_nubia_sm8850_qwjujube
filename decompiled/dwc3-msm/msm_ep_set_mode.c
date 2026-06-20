__int64 __fastcall msm_ep_set_mode(__int64 a1, int a2)
{
  __int64 v3; // x8
  _QWORD *v4; // x9

  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL) + 96LL) + 152LL);
  if ( !a2 )
  {
    if ( *(unsigned __int8 *)(a1 + 170) >= 0x21uLL )
      goto LABEL_6;
    v4 = (_QWORD *)(v3 + 40LL * *(unsigned __int8 *)(a1 + 170));
    v4[163] = 0;
    v4[162] = 0;
    v4[161] = 0;
    v4[160] = 0;
    v4[159] = 0;
  }
  if ( *(unsigned __int8 *)(a1 + 170) <= 0x1FuLL )
  {
    *(_DWORD *)(v3 + 40LL * *(unsigned __int8 *)(a1 + 170) + 1280) = a2;
    return 0;
  }
LABEL_6:
  __break(0x5512u);
  __asm { LDTRSB          W2, [X22,#0x3C] }
  return dwc3_msm_notify_event();
}
