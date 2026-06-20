_BYTE *__fastcall rmnet_shs_is_skb_stamping_reqd(__int64 a1, _BYTE *a2)
{
  _BYTE *result; // x0
  int v5; // w8
  int v6; // w9
  unsigned int v7; // w8
  int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x22
  __int64 v13; // x24
  int v14; // w8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x22
  __int64 v19; // x24
  int v20; // w11
  int v21; // w8
  int v22; // [xsp+8h] [xbp-B8h] BYREF
  __int16 v23; // [xsp+Ch] [xbp-B4h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-B0h] BYREF
  int v25; // [xsp+20h] [xbp-A0h]
  _QWORD v26[6]; // [xsp+90h] [xbp-30h] BYREF

  v26[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v24[0] = 0;
  v24[1] = 0;
  memset(v26, 0, 40);
  v23 = 0;
  v22 = 0;
  if ( (unsigned int)rmnet_module_hook_perf_ingress(&v22, a1) )
  {
    result = nullptr;
    if ( !v22 )
      goto LABEL_52;
  }
  v5 = *(unsigned __int16 *)(a1 + 180);
  if ( v5 == 56710 )
  {
    result = (_BYTE *)((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD *))rmnet_shs_header_ptr)(a1, 0, 40, v26);
    if ( !result )
      goto LABEL_52;
    v7 = (unsigned __int8)result[6];
    if ( v7 <= 0x2B )
    {
      result = (_BYTE *)&unk_1;
      if ( v7 != 6 && v7 != 17 )
        goto LABEL_51;
      goto LABEL_52;
    }
    if ( v7 != 44 )
    {
      if ( v7 != 50 )
      {
        if ( v7 == 58 )
        {
          v8 = *(_DWORD *)(a1 + 129);
          *(_DWORD *)(a1 + 152) = 0;
          *(_DWORD *)(a1 + 129) = v8 | 0x400;
          v9 = ktime_get_with_offset(1);
          v10 = ns_to_timespec64(v9);
          v12 = qword_19478;
          if ( v10 <= 0x225C17D03LL )
            v13 = v11 + 1000000000 * v10;
          else
            v13 = 0x7FFFFFFFFFFFFFFFLL;
          if ( (hrtimer_active(&unk_18FB0) & 1) != 0 )
          {
            hrtimer_cancel(&unk_18FB0);
            hrtimer_start_range_ns(&unk_18FB0, 1200000000, 0, 3);
          }
          else
          {
            hrtimer_start_range_ns(&unk_18FB0, 1200000000, 0, 3);
            _pm_stay_awake(qword_19480);
          }
          rmnet_shs_wake = 2;
          if ( (hrtimer_active(&unk_18F70) & 1) != 0
            || (hrtimer_start_range_ns(&unk_18F70, 950000000, 0, 3), v13 - v12 > 200999999) && qword_19478 )
          {
            ++rmnet_shs_mid_err;
          }
          else
          {
            *a2 = 1;
          }
        }
        goto LABEL_51;
      }
      goto LABEL_38;
    }
    if ( (*(_DWORD *)(a1 + 112) & 0xFFFFFFFE) != 0x28 )
    {
      result = (_BYTE *)skb_header_pointer_0(a1, &v23);
      if ( !result )
        goto LABEL_52;
      if ( *result == 50 )
      {
LABEL_38:
        v20 = rmnet_shs_esp_pkts;
        result = nullptr;
        v21 = *(_DWORD *)(a1 + 129) | 0x400;
        *(_DWORD *)(a1 + 152) = 11184810;
        *(_DWORD *)(a1 + 129) = v21;
        rmnet_shs_esp_pkts = v20 + 1;
        goto LABEL_52;
      }
    }
LABEL_51:
    result = nullptr;
    goto LABEL_52;
  }
  if ( v5 != 8 )
    goto LABEL_51;
  result = (_BYTE *)((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD *))rmnet_shs_header_ptr)(a1, 0, 20, v24);
  if ( !result )
    goto LABEL_52;
  v6 = (unsigned __int8)result[9];
  if ( (*((_WORD *)result + 3) & 0xFF3F) != 0 )
  {
    if ( v6 != 50 )
    {
      if ( v6 != 1 )
        goto LABEL_51;
LABEL_27:
      v14 = *(_DWORD *)(a1 + 129);
      *(_DWORD *)(a1 + 152) = 0;
      *(_DWORD *)(a1 + 129) = v14 | 0x400;
      v15 = ktime_get_with_offset(1);
      v16 = ns_to_timespec64(v15);
      v18 = qword_19478;
      if ( v16 <= 0x225C17D03LL )
        v19 = v17 + 1000000000 * v16;
      else
        v19 = 0x7FFFFFFFFFFFFFFFLL;
      if ( (hrtimer_active(&unk_18FB0) & 1) != 0 )
      {
        hrtimer_cancel(&unk_18FB0);
        hrtimer_start_range_ns(&unk_18FB0, 1200000000, 0, 3);
      }
      else
      {
        hrtimer_start_range_ns(&unk_18FB0, 1200000000, 0, 3);
        _pm_stay_awake(qword_19480);
      }
      rmnet_shs_wake = 2;
      if ( (hrtimer_active(&unk_18F70) & 1) != 0
        || (hrtimer_start_range_ns(&unk_18F70, 950000000, 0, 3), v19 - v18 > 200999999) && qword_19478 )
      {
        ++rmnet_shs_mid_err;
      }
      else
      {
        *a2 = 1;
      }
      goto LABEL_51;
    }
    goto LABEL_38;
  }
  result = (_BYTE *)&unk_1;
  if ( v6 > 16 )
  {
    if ( v6 == 17 )
      goto LABEL_52;
    if ( v6 != 50 )
      goto LABEL_51;
    goto LABEL_38;
  }
  if ( v6 == 1 )
    goto LABEL_27;
  if ( v6 != 6 )
    goto LABEL_51;
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
