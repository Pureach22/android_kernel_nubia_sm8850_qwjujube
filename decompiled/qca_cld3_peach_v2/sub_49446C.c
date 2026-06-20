__int64 __fastcall sub_49446C(__int64 a1, __int64 a2)
{
  __int64 v6; // x1

  _T1 = *(_QWORD *)(a2 - 156);
  v6 = a2 - 156;
  __asm { STGP            X26, X5, [X1,#-0x9C]! }
  return sme_set_chip_pwr_save_fail_cb(a1, v6);
}
