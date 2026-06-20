__int64 __fastcall aw882xx_get_rx_en(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 *v9; // x8
  __int64 v10; // x1
  __int64 *v11; // x8
  __int64 v12; // x1
  unsigned int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = aw_componet_codec_ops[0];
  v13 = 0;
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  v7 = v6;
  if ( *(_DWORD *)(v6 + 8) )
  {
    if ( (unsigned int)aw882xx_dsp_get_afe_module_en(0, &v13) )
    {
      v11 = *(__int64 **)(v7 + 64);
      v12 = v11[14];
      if ( !v12 )
        v12 = *v11;
      printk(&unk_22C6D, v12, "aw882xx_get_rx_en");
    }
    *(_QWORD *)(a2 + 72) = v13;
  }
  else
  {
    *(_QWORD *)(a2 + 72) = (unsigned int)g_algo_rx_en;
    v9 = *(__int64 **)(v6 + 64);
    v10 = v9[14];
    if ( !v10 )
      v10 = *v9;
    printk(&unk_27B72, v10, "aw882xx_get_rx_en");
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
