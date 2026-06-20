__int64 __fastcall nl80211_parse_sched_scan_plans(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  _WORD *v6; // x8
  int v7; // w23
  __int64 v8; // x26
  __int64 v9; // x24
  __int64 v10; // x22
  __int64 v11; // x25
  unsigned __int16 *v12; // x27
  __int64 v13; // x8
  unsigned int v14; // w9
  __int64 result; // x0
  __int64 v16; // x8
  unsigned int v17; // w9
  unsigned int v18; // w8
  __int64 v19; // x8
  unsigned int *v20; // x8
  unsigned int v21; // w9
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  __int64 v23; // [xsp+8h] [xbp-18h]
  __int64 v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_WORD **)(a4 + 1800);
  if ( v6 )
  {
    v7 = (unsigned __int16)(*v6 - 4);
    if ( (unsigned int)v7 <= 3 )
    {
      v10 = a2 - 1;
    }
    else
    {
      v8 = a2 & (unsigned int)~(a2 >> 31);
      v9 = 0;
      v10 = a2 - 1;
      v11 = 0;
      v12 = v6 + 2;
      do
      {
        v14 = *v12;
        if ( v14 < 4 || v7 < v14 )
          break;
        v23 = 0;
        v24 = 0;
        v22 = 0;
        if ( v8 == v11 )
        {
          __break(0x800u);
          goto LABEL_27;
        }
        result = _nla_parse(&v22, 2, v12 + 2, (unsigned __int16)(v14 - 4), &nl80211_plan_policy, 0, 0);
        if ( (_DWORD)result )
          goto LABEL_28;
        if ( !v23 )
          goto LABEL_27;
        *(_DWORD *)(*(_QWORD *)(a3 + 72) + v9) = *(_DWORD *)(v23 + 4);
        v16 = *(_QWORD *)(a3 + 72);
        v17 = *(_DWORD *)(v16 + v9);
        if ( !v17 || v17 > *(_DWORD *)(a1 + 148) )
          goto LABEL_27;
        if ( v24 )
        {
          *(_DWORD *)(v16 + v9 + 4) = *(_DWORD *)(v24 + 4);
          v18 = *(_DWORD *)(*(_QWORD *)(a3 + 72) + v9 + 4);
          if ( !v18 || v18 > *(_DWORD *)(a1 + 152) )
            goto LABEL_27;
        }
        else if ( v11 < v10 )
        {
          goto LABEL_27;
        }
        ++v11;
        v9 += 8;
        v13 = (*v12 + 3) & 0x1FFFC;
        v7 -= v13;
        v12 = (unsigned __int16 *)((char *)v12 + v13);
      }
      while ( v7 > 3 );
    }
    if ( *(_DWORD *)(*(_QWORD *)(a3 + 72) + 8 * v10 + 4) )
      result = 4294967274LL;
    else
      result = 0;
  }
  else
  {
    v19 = *(unsigned int *)(*(_QWORD *)(a4 + 952) + 4LL);
    if ( (_DWORD)v19
      && (**(_DWORD **)(a3 + 72) = ((unsigned __int64)(v19 + 999) * (unsigned __int128)0x4189374BC6A7F0uLL) >> 64,
          v20 = *(unsigned int **)(a3 + 72),
          *v20) )
    {
      v21 = *(_DWORD *)(a1 + 148);
      result = 0;
      if ( *v20 > v21 )
        *v20 = v21;
    }
    else
    {
LABEL_27:
      result = 4294967274LL;
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
