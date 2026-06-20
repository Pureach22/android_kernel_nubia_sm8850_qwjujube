__int64 __fastcall sde_encoder_phys_wb_irq_ctrl(__int64 result, char a2)
{
  __int64 v2; // x19
  __int64 v3; // x21
  int v4; // w20
  __int64 v5; // x25
  __int64 v6; // x8
  unsigned __int64 v7; // x24
  unsigned __int64 v8; // x23
  unsigned __int64 v9; // x22
  unsigned int v10; // w1
  unsigned int v11; // w1
  int v12; // w8
  unsigned int v13; // w1
  unsigned int v14; // w1
  int v15; // w8
  __int64 v16; // x0
  unsigned int v17; // w1
  unsigned int v20; // w8
  unsigned int v21; // w8
  unsigned int v28; // w8
  unsigned int v29; // w8

  if ( result )
  {
    v2 = result;
    v3 = *(int *)(*(_QWORD *)(result + 496) + 32LL);
    v4 = v3 - 1;
    if ( (int)v3 + 1 >= 14 )
    {
      return printk(&unk_2472A6, "sde_encoder_phys_wb_irq_ctrl");
    }
    else
    {
      v5 = *(_QWORD *)(*(_QWORD *)(result + 2680) + 56LL);
      v6 = *(_QWORD *)(v5 + 32);
      v7 = (unsigned __int64)(v6 & 0x1000) >> 11;
      v8 = (v6 << 51 >> 63) & 0x38;
      v9 = (v6 << 51 >> 63) & (unsigned __int64)&cwb_irq_tbl;
      if ( (a2 & 1) != 0 )
      {
        while ( 1 )
        {
          _X9 = (unsigned int *)(v2 + 856);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v20 = __ldxr(_X9);
            v21 = v20 + 1;
          }
          while ( __stlxr(v21, _X9) );
          __dmb(0xBu);
          if ( v21 != 1 )
            break;
          sde_encoder_helper_register_irq(v2, 0xAu);
          result = sde_encoder_helper_register_irq(v2, 6u);
          if ( (*(_QWORD *)(v5 + 32) & 0x100000) != 0 )
            result = sde_encoder_helper_register_irq(v2, 0x13u);
          if ( !(_DWORD)v7 )
            goto LABEL_14;
          if ( v8 > 4LL * v4 )
          {
            v10 = *(_DWORD *)(v9 + 4LL * v4);
            if ( v10 )
              result = sde_encoder_helper_register_irq(v2, v10);
            if ( v8 > 4 * v3 )
            {
              v11 = *(_DWORD *)(v9 + 4 * v3);
              if ( v11 )
                result = sde_encoder_helper_register_irq(v2, v11);
LABEL_14:
              v12 = *(_DWORD *)(*(_QWORD *)(v2 + 496) + 48LL);
              if ( (unsigned int)(v12 - 3) < 2 )
                return sde_encoder_helper_register_irq(v2, 0x11u);
              if ( (unsigned int)(v12 - 1) <= 1 )
                return sde_encoder_helper_register_irq(v2, 0x10u);
              return result;
            }
          }
LABEL_35:
          __break(1u);
        }
      }
      else
      {
        _X9 = (unsigned int *)(result + 856);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v28 = __ldxr(_X9);
          v29 = v28 - 1;
        }
        while ( __stlxr(v29, _X9) );
        __dmb(0xBu);
        if ( !v29 )
        {
          sde_encoder_helper_unregister_irq(result, 0xAu);
          result = sde_encoder_helper_unregister_irq(v2, 6u);
          if ( (*(_QWORD *)(v5 + 32) & 0x100000) != 0 )
            result = sde_encoder_helper_unregister_irq(v2, 0x13u);
          if ( (_DWORD)v7 )
          {
            if ( v8 <= 4LL * v4 )
              goto LABEL_35;
            v13 = *(_DWORD *)(v9 + 4LL * v4);
            if ( v13 )
              result = sde_encoder_helper_unregister_irq(v2, v13);
            if ( v8 <= 4 * v3 )
              goto LABEL_35;
            v14 = *(_DWORD *)(v9 + 4 * v3);
            if ( v14 )
              result = sde_encoder_helper_unregister_irq(v2, v14);
          }
          v15 = *(_DWORD *)(*(_QWORD *)(v2 + 496) + 48LL);
          if ( (unsigned int)(v15 - 3) < 2 )
          {
            v16 = v2;
            v17 = 17;
          }
          else
          {
            if ( (unsigned int)(v15 - 1) > 1 )
              return result;
            v16 = v2;
            v17 = 16;
          }
          return sde_encoder_helper_unregister_irq(v16, v17);
        }
      }
    }
  }
  return result;
}
