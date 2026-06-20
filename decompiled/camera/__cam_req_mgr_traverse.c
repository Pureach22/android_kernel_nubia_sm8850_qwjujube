__int64 __fastcall _cam_req_mgr_traverse(__int64 a1)
{
  _DWORD *v2; // x7
  __int64 v3; // x19
  signed int v4; // w21
  __int64 v5; // x25
  __int64 v6; // x8
  _DWORD *v7; // x25
  __int64 result; // x0
  char v9; // w10
  int v10; // w8
  char *v11; // x10
  char *v12; // x8
  _DWORD *v13; // x20
  _DWORD *v14; // [xsp+28h] [xbp-18h]
  signed int v15; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 24);
  v2 = *(_DWORD **)(a1 + 32);
  v4 = *(_DWORD *)a1;
  v15 = *(_DWORD *)a1;
  if ( !v3 || !v2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "__cam_req_mgr_traverse",
      674,
      "NULL pointer %pK %pK",
      (const void *)v3,
      v2);
    *(_DWORD *)(a1 + 4) = 0;
    result = 4294967274LL;
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (unsigned int)v4 < 0x31 )
  {
    v5 = v3 + 48LL * v4;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    {
      if ( v4 != 48 )
      {
        v14 = v2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10,
          4,
          "__cam_req_mgr_traverse",
          686,
          "Enter pd %d idx %d state %d skip %d status %d skip_idx %d",
          *(_DWORD *)(v3 + 4),
          v4,
          *(_DWORD *)(v5 + 52),
          *(_DWORD *)(v3 + 16),
          *(_DWORD *)(*(_QWORD *)(a1 + 40) + 72LL * v4 + 16),
          *(_DWORD *)(*(_QWORD *)(a1 + 40) + 72LL * v4 + 12));
        v2 = v14;
        goto LABEL_7;
      }
    }
    else if ( v4 != 48 )
    {
LABEL_7:
      if ( *(_DWORD *)(v5 + 52) == 2
        || (v6 = *(_QWORD *)(a1 + 40) + 72LL * v4, *(_DWORD *)(v6 + 12) == 1)
        || *(int *)(v3 + 16) >= 1 )
      {
        if ( !*(_QWORD *)(v3 + 24)
          || (v7 = v2,
              cam_common_dec_idx(&v15, *(unsigned int *)(v3 + 32)),
              *(_DWORD *)a1 = v15,
              *(_QWORD *)(a1 + 24) = *(_QWORD *)(v3 + 24),
              result = _cam_req_mgr_traverse(a1),
              v2 = v7,
              (result & 0x80000000) == 0) )
        {
          v9 = *(_BYTE *)(a1 + 48);
          *(_DWORD *)(a1 + 4) |= 1 << *(_DWORD *)(v3 + 4);
          if ( (v9 & 1) != 0 )
            goto LABEL_13;
          v10 = *(_DWORD *)(v3 + 4);
          v11 = (char *)&v2[6 * v10];
          *((_DWORD *)v11 + 1) = v10;
          *((_QWORD *)v11 + 1) = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 72LL * v4 + 24);
          v2[6 * *(int *)(v3 + 4)] = v4;
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
          {
            v12 = (char *)&v2[6 * *(int *)(v3 + 4)];
            v13 = v2;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "__cam_req_mgr_traverse",
              711,
              "req_id: %lld with pd of %d",
              *((_QWORD *)v12 + 1),
              *((_DWORD *)v12 + 1));
            v2 = v13;
          }
          if ( *(int *)(v3 + 16) < 1 )
          {
LABEL_13:
            result = 0;
          }
          else
          {
            result = 0;
            *(_QWORD *)&v2[6 * *(int *)(v3 + 4) + 2] = -1;
            --*(_DWORD *)(v3 + 16);
          }
        }
      }
      else
      {
        result = 4294967285LL;
        *(_QWORD *)(a1 + 8) = *(_QWORD *)(v6 + 24);
        *(_DWORD *)(a1 + 16) = *(_DWORD *)(v3 + 4);
        *(_DWORD *)(a1 + 20) = *(_DWORD *)(v5 + 44) & *(_DWORD *)(v3 + 12);
        *(_DWORD *)(a1 + 4) &= ~(1 << *(_DWORD *)(v3 + 4));
      }
      goto LABEL_15;
    }
  }
  __break(0x5512u);
  return _cam_req_mgr_tbl_set_id();
}
