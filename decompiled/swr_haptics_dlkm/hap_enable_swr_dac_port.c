__int64 __fastcall hap_enable_swr_dac_port(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  _QWORD *v4; // x19
  char v5; // w9
  int v6; // w10
  char v7; // w8
  char v8; // w9
  int v9; // w10
  char v10; // w9
  unsigned int v11; // w20
  int v12; // w10
  char v13; // w8
  char v14; // w9
  __int64 result; // x0
  unsigned int v16; // w0
  unsigned int v17; // w0
  unsigned int v18; // w0
  unsigned int v19; // w20
  unsigned int v20; // w0
  char v21; // w8
  unsigned int v22; // w0
  int v23; // w0
  unsigned int v24; // w0
  int v25; // w0
  int v26; // w21
  int v27; // w0
  int v28; // w21
  unsigned int v29; // w8
  char v30; // w11
  unsigned int v31; // w0
  int v32; // [xsp+Ch] [xbp-24h] BYREF
  _WORD v33[2]; // [xsp+10h] [xbp-20h] BYREF
  __int16 v34; // [xsp+14h] [xbp-1Ch] BYREF
  _WORD v35[2]; // [xsp+18h] [xbp-18h] BYREF
  _WORD v36[2]; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v37[2]; // [xsp+20h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v36[0] = 0;
  v35[0] = 0;
  v34 = 0;
  v33[0] = 0;
  v37[0] = 0;
  v32 = 0;
  if ( v3 == 208 )
  {
    printk(&unk_77E4, "hap_enable_swr_dac_port");
    result = 4294967274LL;
    goto LABEL_86;
  }
  v4 = *(_QWORD **)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( !v4 )
  {
    printk(&unk_7BA0, "hap_enable_swr_dac_port");
    result = 4294967277LL;
    goto LABEL_86;
  }
  v5 = *((_BYTE *)v4 + 33);
  v6 = *((_DWORD *)v4 + 9);
  LOBYTE(v36[0]) = *((_BYTE *)v4 + 32);
  v7 = *((_BYTE *)v4 + 40);
  LOBYTE(v35[0]) = v5;
  v8 = *((_BYTE *)v4 + 41);
  LODWORD(v37[0]) = v6;
  v9 = *((unsigned __int8 *)v4 + 187);
  LOBYTE(v34) = v7;
  LOBYTE(v33[0]) = v8;
  if ( v9 )
  {
    v10 = *((_BYTE *)v4 + 45);
    v11 = 2;
    v12 = *((_DWORD *)v4 + 12);
    HIBYTE(v36[0]) = *((_BYTE *)v4 + 44);
    v13 = *((_BYTE *)v4 + 52);
    HIBYTE(v35[0]) = v10;
    v14 = *((_BYTE *)v4 + 53);
    HIDWORD(v37[0]) = v12;
    HIBYTE(v34) = v13;
    HIBYTE(v33[0]) = v14;
  }
  else
  {
    v11 = 1;
  }
  result = 0;
  if ( a3 <= 3 )
  {
    if ( a3 != 1 )
    {
      if ( a3 == 2 )
      {
        if ( !v4[8] || (*((_BYTE *)v4 + 182) & 1) != 0 )
          goto LABEL_14;
        v16 = ((__int64 (*)(void))regulator_set_voltage)();
        if ( (v16 & 0x80000000) != 0 )
        {
          v19 = v16;
          if ( (unsigned int)__ratelimit(&swr_hap_enable_hpwr_vreg__rs, "swr_hap_enable_hpwr_vreg") )
            dev_err(*v4, "%s: Set hpwr voltage failed, rc=%d\n", "swr_hap_enable_hpwr_vreg", v19);
        }
        else
        {
          v17 = regulator_enable(v4[8]);
          if ( (v17 & 0x80000000) == 0 )
          {
            *((_BYTE *)v4 + 182) = 1;
LABEL_14:
            mutex_lock(v4 + 15);
            v18 = regmap_write(v4[3], 12417, 132);
            if ( v18 )
            {
              v19 = v18;
              if ( (unsigned int)__ratelimit(&hap_enable_swr_dac_port__rs_39, "hap_enable_swr_dac_port") )
                dev_err(*v4, "%s: Enable SWR_PLAY failed, rc=%d\n", "hap_enable_swr_dac_port", v19);
              swr_hap_disable_hpwr_vreg(v4);
LABEL_40:
              swr_device_wakeup_unvote(v4[1]);
              mutex_unlock(v4 + 15);
LABEL_85:
              result = v19;
              goto LABEL_86;
            }
            *((_BYTE *)v4 + 181) = 1;
            mutex_unlock(v4 + 15);
            swr_slvdev_datapath_control(v4[1], *(unsigned __int8 *)(v4[1] + 64LL), 1);
            if ( *((_BYTE *)v4 + 187) )
            {
              v25 = regmap_write(v4[3], 12419, 20);
              if ( v25 )
                dev_err(*v4, "%s: 0x%x reg write failed, rc = %d\n", "hap_enable_swr_dac_port", 12419, v25);
            }
            swr_device_wakeup_unvote(v4[1]);
            goto LABEL_47;
          }
          v19 = v17;
          if ( (unsigned int)__ratelimit(&swr_hap_enable_hpwr_vreg__rs_48, "swr_hap_enable_hpwr_vreg") )
            dev_err(*v4, "%s: Enable hpwr failed, rc=%d\n", "swr_hap_enable_hpwr_vreg", v19);
          regulator_set_voltage(v4[8], 0, 0x7FFFFFFF);
        }
        if ( (unsigned int)__ratelimit(&hap_enable_swr_dac_port__rs_37, "hap_enable_swr_dac_port") )
          dev_err(*v4, "%s: Enable hpwr_vreg failed, rc=%d\n", "hap_enable_swr_dac_port", v19);
LABEL_67:
        swr_device_wakeup_unvote(v4[1]);
        goto LABEL_85;
      }
      goto LABEL_86;
    }
    v21 = *((_BYTE *)v4 + 186);
    if ( (v21 & 2) != 0 && (*((_BYTE *)v4 + 180) & 1) == 0 )
    {
      v22 = regulator_enable(v4[7]);
      if ( (v22 & 0x80000000) != 0 )
      {
        v19 = v22;
        if ( (unsigned int)__ratelimit(&swr_haptics_slave_enable__rs, "swr_haptics_slave_enable") )
          dev_err(*v4, "%s: enable swr-slave-vdd failed, rc=%d\n", "swr_haptics_slave_enable", v19);
        if ( (unsigned int)__ratelimit(&hap_enable_swr_dac_port__rs, "hap_enable_swr_dac_port") )
          dev_err(*v4, "%s: enable haptics failed, rc=%d\n", "hap_enable_swr_dac_port", v19);
        goto LABEL_85;
      }
      v21 = *((_BYTE *)v4 + 186);
      *((_BYTE *)v4 + 180) = 1;
    }
    if ( (v21 & 1) == 0 || *((_BYTE *)v4 + 183) != 1 )
    {
LABEL_75:
      v29 = *((unsigned __int8 *)v4 + 184);
      if ( v29 >= *((unsigned __int8 *)v4 + 185) )
        v30 = *((_BYTE *)v4 + 185);
      else
        v30 = *((_BYTE *)v4 + 184);
      if ( *((_BYTE *)v4 + 185) )
        LOBYTE(v29) = v30;
      if ( *((_BYTE *)v4 + 187) )
        LOBYTE(v29) = -82;
      v31 = regmap_write(v4[3], 12418, (unsigned __int8)v29);
      if ( !v31 )
      {
        regmap_read(v4[3], 12418, &v32);
        regmap_read(v4[3], 12416, &v32);
        swr_device_wakeup_vote(v4[1]);
        swr_connect_port(v4[1], v36, v11, v35, v37, &v34, v33);
        result = 0;
        goto LABEL_86;
      }
      v19 = v31;
      if ( (unsigned int)__ratelimit(&hap_enable_swr_dac_port__rs_35, "hap_enable_swr_dac_port") )
        dev_err(*v4, "%s: SWR_VMAX update failed, rc=%d\n", "hap_enable_swr_dac_port", v19);
      goto LABEL_85;
    }
    if ( *((_BYTE *)v4 + 180) == 1 )
    {
      v23 = regulator_disable(v4[7]);
      if ( (v23 & 0x80000000) == 0 )
      {
        *((_BYTE *)v4 + 180) = 0;
        if ( (*((_BYTE *)v4 + 180) & 1) != 0 )
          goto LABEL_74;
        goto LABEL_70;
      }
      v26 = v23;
      if ( (unsigned int)__ratelimit(&swr_haptics_slave_disable__rs, "swr_haptics_slave_disable") )
      {
        dev_err(*v4, "%s: disable swr-slave-vdd failed, rc=%d\n", "swr_haptics_slave_disable", v26);
        if ( (*((_BYTE *)v4 + 180) & 1) != 0 )
          goto LABEL_74;
        goto LABEL_70;
      }
    }
    if ( (*((_BYTE *)v4 + 180) & 1) != 0 )
    {
LABEL_74:
      *((_BYTE *)v4 + 183) = 0;
      goto LABEL_75;
    }
LABEL_70:
    v27 = regulator_enable(v4[7]);
    if ( v27 < 0 )
    {
      v28 = v27;
      if ( (unsigned int)__ratelimit(&swr_haptics_slave_enable__rs, "swr_haptics_slave_enable") )
        dev_err(*v4, "%s: enable swr-slave-vdd failed, rc=%d\n", "swr_haptics_slave_enable", v28);
    }
    else
    {
      *((_BYTE *)v4 + 180) = 1;
    }
    goto LABEL_74;
  }
  if ( a3 == 4 )
  {
    mutex_lock(v4 + 15);
    if ( (*((_BYTE *)v4 + 188) & 1) == 0 )
    {
      swr_device_wakeup_vote(v4[1]);
      v24 = regmap_write(v4[3], 12417, 4);
      if ( v24 )
      {
        v19 = v24;
        if ( (unsigned int)__ratelimit(&hap_enable_swr_dac_port__rs_42, "hap_enable_swr_dac_port") )
          dev_err(*v4, "%s: Enable SWR_PLAY failed, rc=%d\n", "hap_enable_swr_dac_port", v19);
        goto LABEL_40;
      }
      swr_device_wakeup_unvote(v4[1]);
    }
    *((_BYTE *)v4 + 181) = 0;
    mutex_unlock(v4 + 15);
    v19 = swr_hap_disable_hpwr_vreg(v4);
    result = 0;
    if ( (v19 & 0x80000000) != 0 )
    {
      if ( (unsigned int)__ratelimit(&hap_enable_swr_dac_port__rs_43, "hap_enable_swr_dac_port") )
        dev_err(*v4, "%s: Disable hpwr_vreg failed, rc=%d\n", "hap_enable_swr_dac_port", v19);
      goto LABEL_67;
    }
  }
  else if ( a3 == 8 )
  {
    swr_disconnect_port(v4[1], v36, v11, v35, v33);
    if ( (*((_BYTE *)v4 + 188) & 1) == 0 )
    {
      swr_device_wakeup_vote(v4[1]);
      swr_slvdev_datapath_control(v4[1], *(unsigned __int8 *)(v4[1] + 64LL), 0);
      swr_device_wakeup_unvote(v4[1]);
    }
    if ( (*((_BYTE *)v4 + 186) & 2) == 0 || *((_BYTE *)v4 + 180) != 1 )
    {
LABEL_47:
      result = 0;
      goto LABEL_86;
    }
    v20 = regulator_disable(v4[7]);
    if ( (v20 & 0x80000000) != 0 )
    {
      v19 = v20;
      if ( (unsigned int)__ratelimit(&swr_haptics_slave_disable__rs, "swr_haptics_slave_disable") )
        dev_err(*v4, "%s: disable swr-slave-vdd failed, rc=%d\n", "swr_haptics_slave_disable", v19);
      if ( (unsigned int)__ratelimit(&hap_enable_swr_dac_port__rs_45, "hap_enable_swr_dac_port") )
        dev_err(*v4, "%s: disable haptics failed, rc=%d\n", "hap_enable_swr_dac_port", v19);
      goto LABEL_85;
    }
    result = 0;
    *((_BYTE *)v4 + 180) = 0;
  }
LABEL_86:
  _ReadStatusReg(SP_EL0);
  return result;
}
