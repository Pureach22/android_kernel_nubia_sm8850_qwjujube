__int64 __fastcall rmnet_shs_genl_try_to_move_flow(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x1
  __int64 v5; // x0
  int v6; // w1
  __int64 result; // x0
  __int64 v8; // x0
  int v9; // w1
  __int64 v10; // x0
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  int v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_19;
  v2 = *(_QWORD *)(a2 + 32);
  v12 = 0;
  v11 = 0;
  v4 = *(_QWORD *)(v2 + 24);
  if ( v4 && (int)nla_memcpy(&v11, v4, 12) >= 1 )
  {
    if ( HIWORD(v12) > 7u || (unsigned __int16)v12 >= 8u )
    {
      ++qword_1A3A0;
      goto LABEL_17;
    }
    if ( SHIDWORD(v11) <= 5 )
    {
      if ( HIDWORD(v11) == 4 )
      {
        ++qword_1A238;
        if ( ((1 << SBYTE2(v12)) & (unsigned __int8)word_1949D) != 0 )
        {
          if ( (rmnet_shs_halt_mask & (1 << SBYTE2(v12))) != 0 )
          {
            ++qword_1A288;
            goto LABEL_17;
          }
          if ( HIWORD(v12) == BYTE2(dword_19499) && HIWORD(v12) == (unsigned __int8)dword_19499 )
            goto LABEL_32;
          if ( (((unsigned __int8)word_1949D >> SBYTE2(dword_19499)) & 1) != 0 )
            ++qword_1A298;
          LOBYTE(dword_19499) = BYTE2(v12);
          goto LABEL_40;
        }
LABEL_30:
        v8 = a2;
        v9 = 300;
        goto LABEL_18;
      }
      if ( HIDWORD(v11) == 5 )
      {
        ++qword_1A230;
        if ( ((1 << SBYTE2(v12)) & HIBYTE(word_1949D)) != 0 && ((HIBYTE(word_1949D) >> dword_19499) & 1) == 0 )
        {
          if ( (rmnet_shs_halt_mask & (1 << SBYTE2(v12))) != 0 )
          {
            ++qword_1A290;
LABEL_17:
            v8 = a2;
            v9 = 301;
LABEL_18:
            rmnet_shs_genl_send_int_to_userspace(v8, v9);
LABEL_19:
            result = 0xFFFFFFFFLL;
            goto LABEL_20;
          }
          LOBYTE(dword_19499) = BYTE2(v12);
LABEL_40:
          _rcu_read_lock((unsigned __int16)v12);
          v10 = rmnet_shs_switch_enable();
          _rcu_read_unlock(v10);
          goto LABEL_32;
        }
        goto LABEL_30;
      }
LABEL_24:
      if ( rmnet_shs_wq_try_to_move_flow(v12, HIWORD(v12), v11, HIDWORD(v11)) )
        rmnet_shs_genl_send_int_to_userspace(a2, 727);
      else
        rmnet_shs_genl_send_int_to_userspace(a2, 720);
      trace_rmnet_shs_wq_high();
      goto LABEL_15;
    }
    if ( HIDWORD(v11) == 7 )
    {
      rmnet_shs_ll_phy_cpu = HIWORD(v12);
    }
    else
    {
      if ( HIDWORD(v11) != 6 )
        goto LABEL_24;
      rmnet_shs_ll_flow_cpu = HIWORD(v12);
    }
LABEL_32:
    v5 = a2;
    v6 = 300;
    goto LABEL_14;
  }
  v5 = a2;
  v6 = 720;
LABEL_14:
  rmnet_shs_genl_send_int_to_userspace(v5, v6);
LABEL_15:
  result = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
