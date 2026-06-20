__int64 __fastcall aw882xx_hw_params(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v4)(); // x9
  __int64 v6; // x0
  __int64 v7; // x0
  int v8; // w8
  __int64 *v10; // x8
  __int64 v11; // x21
  unsigned int v12; // w8
  __int64 v13; // x23
  __int64 v14; // x0
  int v15; // w9
  __int64 *v16; // x8
  __int64 v17; // x20
  unsigned int v18; // w8
  __int64 v19; // x0
  int v20; // w9

  v4 = off_350;
  v6 = *(_QWORD *)(a3 + 96);
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8229u);
  v7 = ((__int64 (__fastcall *)(__int64))v4)(v6);
  v8 = *(_DWORD *)(a1 + 60);
  if ( v8 == 1 )
  {
    v10 = *(__int64 **)(v7 + 64);
    v11 = v10[14];
    if ( !v11 )
      v11 = *v10;
    v12 = *(_DWORD *)(a2 + 36);
    if ( v12 )
    {
      v15 = 0;
    }
    else
    {
      v12 = *(_DWORD *)(a2 + 40);
      if ( !v12 )
      {
        v13 = v7;
        v14 = 0;
        goto LABEL_14;
      }
      v15 = 32;
    }
    v13 = v7;
    v14 = __clz(__rbit32(v12)) | v15;
LABEL_14:
    snd_pcm_format_width(v14);
    printk(&unk_23DDD, v11, "aw882xx_hw_params");
    v7 = v13;
    if ( *(_DWORD *)(a1 + 60) )
      return 0;
LABEL_15:
    v16 = *(__int64 **)(v7 + 64);
    v17 = v16[14];
    if ( !v17 )
      v17 = *v16;
    v18 = *(_DWORD *)(a2 + 36);
    if ( v18 )
    {
      v20 = 0;
    }
    else
    {
      v18 = *(_DWORD *)(a2 + 40);
      if ( !v18 )
      {
        v19 = 0;
LABEL_23:
        snd_pcm_format_width(v19);
        printk(&unk_22850, v17, "aw882xx_hw_params");
        return 0;
      }
      v20 = 32;
    }
    v19 = __clz(__rbit32(v18)) | v20;
    goto LABEL_23;
  }
  if ( !v8 )
    goto LABEL_15;
  return 0;
}
