__int64 __fastcall msm_vidc_set_u32_packed(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned __int64 v3; // x4

  _ReadStatusReg(SP_EL0);
  if ( a2 >= 0xC6 )
    __break(0x5512u);
  if ( (*(_BYTE *)(a1 + 4320 + 168LL * a2 + 48) & 2) == 0 )
    goto LABEL_3;
  if ( a2 == 41 )
  {
    v3 = *(_QWORD *)(a1 + 11240);
    if ( v3 > 1 && a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8A39B, "err ", a1 + 340, "msm_vidc_v4l2_menu_to_hfi", v3);
LABEL_3:
    result = ((__int64 (*)(void))msm_vidc_packetize_control)();
    goto LABEL_10;
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_8C607, "err ", a1 + 340, "msm_vidc_v4l2_menu_to_hfi", *(unsigned int *)(a1 + 4320 + 168LL * a2 + 40));
    result = 4294967274LL;
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
