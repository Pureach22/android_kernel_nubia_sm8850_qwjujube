__int64 __fastcall aw882xx_start_pa(__int64 a1)
{
  __int64 *v1; // x8
  __int64 v3; // x1
  int v4; // w20
  __int64 *v5; // x8
  __int64 v6; // x1
  void *v7; // x0
  __int64 *v8; // x8
  __int64 result; // x0
  __int64 *v10; // x8
  __int64 v11; // x1
  void *v12; // x0
  __int64 *v13; // x8
  __int64 *v14; // x8
  __int64 *v15; // x8
  __int64 *v16; // x8

  v1 = *(__int64 **)(a1 + 64);
  v3 = v1[14];
  if ( !v3 )
    v3 = *v1;
  printk(&unk_26EB3, v3, "aw882xx_start_pa");
  if ( *(_BYTE *)(a1 + 36) == 1 )
  {
    if ( *(_BYTE *)(a1 + 19) )
    {
      v4 = 0;
      while ( !**(_DWORD **)(a1 + 96) )
      {
        if ( !*(_DWORD *)(a1 + 8) )
        {
          v13 = *(__int64 **)(a1 + 64);
          v11 = v13[14];
          if ( !v11 )
            v11 = *v13;
          v12 = &unk_2606C;
          return printk(v12, v11, "aw882xx_start_pa");
        }
        if ( (unsigned int)aw882xx_dev_reg_update() )
        {
          v8 = *(__int64 **)(a1 + 64);
          v6 = v8[14];
          if ( !v6 )
            v6 = *v8;
          v7 = &unk_258E3;
        }
        else
        {
          if ( !(unsigned int)aw882xx_device_start(*(_QWORD *)(a1 + 96)) )
          {
            if ( *(_BYTE *)(a1 + 17) )
              queue_delayed_work_on(32, *(_QWORD *)(a1 + 104), a1 + 320, 250);
            v16 = *(__int64 **)(a1 + 64);
            v11 = v16[14];
            if ( !v11 )
              v11 = *v16;
            v12 = &unk_2590F;
            return printk(v12, v11, "aw882xx_start_pa");
          }
          v5 = *(__int64 **)(a1 + 64);
          v6 = v5[14];
          if ( !v6 )
            v6 = *v5;
          v7 = &unk_26F21;
        }
        result = printk(v7, v6, "aw882xx_start_pa");
        if ( ++v4 == 5 )
          return result;
      }
      v10 = *(__int64 **)(a1 + 64);
      v11 = v10[14];
      if ( !v11 )
        v11 = *v10;
      v12 = &unk_24A2B;
    }
    else
    {
      v15 = *(__int64 **)(a1 + 64);
      v11 = v15[14];
      if ( !v11 )
        v11 = *v15;
      v12 = &unk_26EF5;
    }
  }
  else
  {
    v14 = *(__int64 **)(a1 + 64);
    v11 = v14[14];
    if ( !v11 )
      v11 = *v14;
    v12 = &unk_23E41;
  }
  return printk(v12, v11, "aw882xx_start_pa");
}
