__int64 __fastcall wlan_dp_lapb_handle_frame(__int64 result, __int64 a2, _DWORD *a3, __int64 a4)
{
  unsigned __int64 v4; // x23
  __int64 v5; // x20
  __int64 v6; // x19
  _DWORD *v7; // x21
  __int64 context; // x0
  __int64 v9; // x8
  __int64 v10; // x8
  _DWORD *v11; // x19
  _DWORD *v12; // x19
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v14; // x22
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x19
  __int64 v18; // x3

  v4 = *(unsigned int *)(a2 + 168);
  if ( (v4 & 0xF000000) == 0xB000000 )
  {
    v5 = result + 0x4000;
    if ( (v4 & 0x10000000) != 0 )
    {
      v10 = result + 19816;
      if ( *(_DWORD *)a4 == 1 && *(_BYTE *)(a4 + 95) )
      {
        if ( (*(_BYTE *)(result + 19872) & 1) != 0 && *(_QWORD *)(*(_QWORD *)(result + 19864) + 24LL) != v10 )
        {
          v11 = a3;
          result = hrtimer_cancel(result + 19816);
          a3 = v11;
        }
        *a3 = 1;
      }
      else
      {
        if ( (*(_BYTE *)(result + 19872) & 1) != 0 && *(_QWORD *)(*(_QWORD *)(result + 19864) + 24LL) != v10 )
        {
          v12 = a3;
          result = hrtimer_cancel(result + 19816);
          a3 = v12;
        }
        *a3 = 0;
        ++*(_DWORD *)(v5 + 3528);
      }
    }
    else
    {
      v6 = result;
      v7 = a3;
      context = dp_get_context();
      if ( context )
        v9 = *(_QWORD *)(context + 1552);
      else
        v9 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      v14 = 0;
      *(_DWORD *)(StatusReg + 16) += 512;
      if ( (v4 & 0xE00000) == 0 && v9 )
      {
        v15 = *(_QWORD *)(v9 + 8 * ((v4 >> 16) & 0x1F));
        if ( v15 )
          v14 = *(unsigned int *)(v15 + 20);
        else
          v14 = 0;
      }
      result = local_bh_enable_6();
      v16 = *(_QWORD *)(v6 + 19864);
      v17 = v6 + 19816;
      if ( *(_QWORD *)(v16 + 24) != v17 )
      {
        if ( (*(_BYTE *)(v5 + 3488) & 1) == 0 || (result = _hrtimer_get_remaining(v17, 0), result / 1000000 > v14) )
        {
          if ( *(_DWORD *)(v5 + 3496) == 1 )
            v18 = 5;
          else
            v18 = 1;
          result = hrtimer_start_range_ns(v17, 1000000LL * (unsigned int)v14, 0, v18);
        }
      }
      *v7 = 1;
    }
    ++*(_DWORD *)(v5 + 3520);
  }
  return result;
}
