__int64 __fastcall i2c_pmic_irq_handler(unsigned int a1, _QWORD *a2)
{
  char v4; // w8
  int v5; // w8
  __int64 v6; // x22
  int v7; // w8
  int v8; // w9
  int v9; // w8
  int v10; // w0
  unsigned int v11; // w21
  __int64 v12; // x8
  int v13; // w20
  unsigned int v14; // w10
  __int64 v15; // x22
  unsigned __int16 *v16; // x22
  int v17; // t1
  int v18; // w0
  unsigned int v19; // w27
  __int64 v20; // x28
  __int64 v21; // x0
  __int64 v22; // x22
  __int64 v23; // x23
  bool v24; // zf
  __int64 v25; // x8
  __int64 v26; // x26
  int v27; // w0
  int v28; // w20
  int v29; // w0
  int v30; // w20
  int v31; // w20
  __int64 v33; // [xsp+8h] [xbp-28h]
  __int64 v34; // [xsp+10h] [xbp-20h]
  char v35; // [xsp+18h] [xbp-18h]
  unsigned int v36; // [xsp+1Ch] [xbp-14h] BYREF
  unsigned int v37; // [xsp+20h] [xbp-10h] BYREF
  int v38; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+28h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  mutex_lock(a2 + 5);
  v4 = *((_BYTE *)a2 + 104);
  *((_BYTE *)a2 + 105) = 1;
  if ( (v4 & 1) != 0 )
  {
    v5 = *((_DWORD *)a2 + 24);
    *((_BYTE *)a2 + 105) = 0;
    if ( v5 + 7 >= 8 )
    {
      v6 = 0;
      do
      {
        v10 = regmap_read(a2[1], (unsigned int)(v6 + 1360), &v36);
        if ( v10 < 0 )
        {
          v31 = v10;
          if ( (unsigned int)__ratelimit(&i2c_pmic_irq_handler__rs, "i2c_pmic_irq_handler") )
            dev_err(*a2, "Couldn't read I2C_INTR_STATUS%d rc=%d\n", v6, v31);
        }
        else
        {
          v11 = v36;
          if ( v36 )
          {
            v33 = v6;
            if ( (_BYTE)v36 )
            {
              v12 = a2[3];
              v37 = 0;
              v34 = v12 + 576 * v6;
              do
              {
                v14 = __clz(__rbit32(v11));
                v15 = v34 + 72LL * v14;
                v35 = v14;
                v17 = *(unsigned __int16 *)(v15 + 8);
                v16 = (unsigned __int16 *)(v15 + 8);
                v18 = regmap_read(a2[1], v17 | 0x18u, &v37);
                if ( v18 < 0 )
                {
                  v13 = v18;
                  if ( (unsigned int)__ratelimit(
                                       &i2c_pmic_summary_status_handler__rs,
                                       "i2c_pmic_summary_status_handler") )
                    dev_err(*a2, "Couldn't read 0x%04x | INT_LATCHED_STS rc=%d\n", *v16, v13);
                }
                else
                {
                  v19 = v37;
                  if ( (_BYTE)v37 )
                  {
                    v20 = *v16;
                    do
                    {
                      v21 = a2[2];
                      v38 = 0;
                      v22 = 1LL << __clz(__rbit32(v19));
                      v23 = v22 | v20;
                      if ( _irq_resolve_mapping(v21, v22 | v20, &v38) )
                        v24 = v38 == 0;
                      else
                        v24 = 1;
                      if ( v24 )
                      {
                        if ( (unsigned int)__ratelimit(
                                             &i2c_pmic_periph_status_handler__rs,
                                             "i2c_pmic_periph_status_handler") )
                          dev_err(*a2, "Couldn't find mapping; disabling 0x%04x\n", v23);
                        v25 = *((unsigned int *)a2 + 24);
                        if ( (int)v25 < 1 )
                        {
LABEL_18:
                          if ( (unsigned int)__ratelimit(&i2c_pmic_find_periph__rs, "i2c_pmic_find_periph") )
                            dev_err(*a2, "Couldn't find periph struct for hwirq 0x%04lx\n", v23);
                        }
                        else
                        {
                          v26 = a2[3] + 24LL;
                          while ( (v20 & 0xFF00) != *(unsigned __int16 *)(v26 - 16) )
                          {
                            --v25;
                            v26 += 72;
                            if ( !v25 )
                              goto LABEL_18;
                          }
                          if ( v26 != 24 )
                          {
                            mutex_lock(v26);
                            *(_BYTE *)(v26 - 10) &= ~(_BYTE)v23;
                            v29 = regmap_write(
                                    a2[1],
                                    ((unsigned int)v22 | (unsigned int)v20) & 0xFF00 | 0x16,
                                    (unsigned __int8)(v22 | v20));
                            if ( v29 < 0 )
                            {
                              v30 = v29;
                              if ( (unsigned int)__ratelimit(&i2c_pmic_irq_disable_now__rs, "i2c_pmic_irq_disable_now") )
                                dev_err(*a2, "Couldn't disable irq 0x%04x rc=%d\n", v23, v30);
                            }
                            else
                            {
                              *(_BYTE *)(v26 - 5) = *(_BYTE *)(v26 - 10);
                            }
                            mutex_unlock(v26);
                          }
                        }
                      }
                      else
                      {
                        handle_nested_irq();
                        v27 = regmap_write(
                                a2[1],
                                ((unsigned int)v22 | (unsigned int)v20) & 0xFF00 | 0x14,
                                (unsigned __int8)(v22 | v20));
                        if ( v27 < 0 )
                        {
                          v28 = v27;
                          if ( (unsigned int)__ratelimit(&i2c_pmic_irq_ack_now__rs, "i2c_pmic_irq_ack_now") )
                            dev_err(*a2, "Couldn't ack 0x%04x rc=%d\n", v23, v28);
                        }
                      }
                      v19 &= ~(_DWORD)v22;
                    }
                    while ( (_BYTE)v19 );
                  }
                }
                v11 &= ~(1 << v35);
              }
              while ( (_BYTE)v11 );
            }
            v6 = v33;
          }
        }
        v7 = *((_DWORD *)a2 + 24);
        ++v6;
        v8 = v7 + 7;
        v9 = v7 + 14;
        if ( v8 >= 0 )
          v9 = v8;
      }
      while ( v6 < v9 >> 3 );
    }
  }
  else
  {
    disable_irq_nosync(a1);
  }
  mutex_unlock(a2 + 5);
  _ReadStatusReg(SP_EL0);
  return 1;
}
