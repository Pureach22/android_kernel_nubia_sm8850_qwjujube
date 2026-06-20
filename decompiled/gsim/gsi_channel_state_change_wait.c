__int64 __fastcall gsi_channel_state_change_wait(unsigned int a1, __int64 a2, unsigned int a3, int a4)
{
  int v7; // w26
  int v8; // w27
  int v9; // w25
  int v10; // w19
  unsigned int v11; // w23
  bool v12; // zf
  int v13; // w8
  __int64 v14; // x0
  __int64 result; // x0
  __int64 ch_reg_idx; // x2
  __int64 v17; // x0
  __int64 v18; // x1
  int v19; // w24
  __int64 v22; // x2
  __int64 v23; // x0
  __int64 v24; // x1
  _QWORD v26[4]; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v27[3]; // [xsp+28h] [xbp-28h] BYREF
  int v28; // [xsp+40h] [xbp-10h]
  __int64 v29; // [xsp+48h] [xbp-8h]

  v7 = 0;
  v8 = 0;
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v10 = 0;
  v28 = 0;
  memset(v27, 0, sizeof(v27));
  v11 = *(_DWORD *)(gsi_ctx + 20);
  memset(v26, 0, sizeof(v26));
  while ( 1 )
  {
    v14 = _msecs_to_jiffies(a3);
    result = wait_for_completion_timeout(a2 + 264, v14);
    if ( (_DWORD)result )
      break;
    ((void (__fastcall *)(__int64, _QWORD, _QWORD *))gsihal_read_reg_n_fields)(6, v11, v27);
    if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
    {
      v17 = 7;
      v18 = v11;
      ch_reg_idx = 0;
    }
    else
    {
      ch_reg_idx = (unsigned int)gsihal_get_ch_reg_idx(a1);
      v17 = 125;
      v18 = v11;
    }
    result = gsihal_read_reg_nk(v17, v18, ch_reg_idx);
    v19 = result;
    if ( *(_DWORD *)(gsi_ctx + 16) == 1 )
    {
      result = gsihal_read_reg_nk_fields(8, v11, a1, v26);
      v9 = HIDWORD(v26[0]);
    }
    if ( v28 )
    {
      result = gsihal_get_ch_reg_mask(a1);
      if ( ((unsigned int)result & v19) != 0 )
      {
        result = gsihal_read_reg_nk_fields(8, v11, a1, v26);
        v9 = HIDWORD(v26[0]);
      }
    }
    if ( a4 != 2 )
    {
      if ( a4 == 1 && (v9 == 2 || v9 == 5) )
        goto LABEL_45;
LABEL_2:
      v12 = v8 == 1 || v7 == 1;
      if ( v12 )
        v13 = 0;
      else
        v13 = v10;
      goto LABEL_8;
    }
    if ( v9 == 4 )
    {
      v12 = v8++ == 0;
      if ( v12 || v7 == 1 )
        v13 = 0;
      else
        v13 = v10;
      if ( v8 == 2 )
      {
        v9 = 4;
LABEL_45:
        *(_DWORD *)(a2 + 120) = v9;
        break;
      }
    }
    else
    {
      if ( v9 != 3 )
        goto LABEL_2;
      if ( v8 == 1 || v7 == 0 )
        v13 = 0;
      else
        v13 = v10;
      if ( v7 == 3 )
      {
        if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
        {
          v23 = 9;
          v24 = v11;
          v22 = 0;
        }
        else
        {
          v22 = (unsigned int)gsihal_get_ch_reg_idx(a1);
          v23 = 129;
          v24 = v11;
        }
        result = gsihal_write_reg_nk(v23, v24, v22);
        v9 = 3;
        goto LABEL_45;
      }
      ++v7;
    }
LABEL_8:
    v10 = v13 + 1;
    if ( v13 >= 4 )
      goto LABEL_45;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
