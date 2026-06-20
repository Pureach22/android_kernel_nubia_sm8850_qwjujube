__int64 __fastcall aw882xx_set_tx_en(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x0
  unsigned int v7; // w19
  __int64 v8; // x20
  __int64 *v9; // x8
  __int64 v10; // x1
  __int64 *v11; // x8
  __int64 v12; // x1
  __int64 *v13; // x8
  __int64 v14; // x1

  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  v7 = *(_DWORD *)(a2 + 72);
  v8 = v6;
  if ( *(_DWORD *)(v6 + 8) )
  {
    if ( (unsigned int)aw882xx_dsp_set_afe_module_en(1, v7) )
    {
      v11 = *(__int64 **)(v8 + 64);
      v12 = v11[14];
      if ( !v12 )
        v12 = *v11;
      printk(&unk_22C6D, v12, "aw882xx_set_tx_en");
    }
  }
  else
  {
    v9 = *(__int64 **)(v6 + 64);
    v10 = v9[14];
    if ( !v10 )
      v10 = *v9;
    printk(&unk_2545D, v10, "aw882xx_set_tx_en");
  }
  v13 = *(__int64 **)(v8 + 64);
  g_algo_tx_en = v7;
  v14 = v13[14];
  if ( !v14 )
    v14 = *v13;
  printk(&unk_22577, v14, "aw882xx_set_tx_en");
  return 0;
}
