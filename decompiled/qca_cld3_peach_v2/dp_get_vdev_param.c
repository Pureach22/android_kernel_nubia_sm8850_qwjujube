__int64 __fastcall dp_get_vdev_param(__int64 a1, unsigned __int8 a2, unsigned int a3, _DWORD *a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x20
  unsigned int v10; // w8
  unsigned int v17; // w10
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int *v26; // x8
  __int64 v27; // x8
  __int64 result; // x0
  _DWORD *v29; // x8
  unsigned int v30; // w8
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x4
  const char *v34; // x3
  unsigned int v37; // w9
  __int64 v38; // x8
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  if ( a2 > 5u )
    return 16;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18984);
  }
  else
  {
    raw_spin_lock_bh(a1 + 18984);
    *(_QWORD *)(a1 + 18992) |= 1uLL;
  }
  v9 = *(_QWORD *)(a1 + 8LL * a2 + 12960);
  if ( v9 )
  {
    v10 = *(_DWORD *)(v9 + 43384);
    while ( v10 )
    {
      _X12 = (unsigned int *)(v9 + 43384);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v17 = __ldxr(_X12);
        if ( v17 != v10 )
          break;
        if ( !__stlxr(v10 + 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v17 == v10;
      v10 = v17;
      if ( _ZF )
      {
        _X8 = (unsigned int *)(v9 + 43416);
        __asm { PRFM            #0x11, [X8] }
        do
          v37 = __ldxr(_X8);
        while ( __stxr(v37 + 1, _X8) );
        v38 = *(_QWORD *)(a1 + 18992);
        if ( (v38 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 18992) = v38 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 18984);
          if ( a3 > 0x20 )
          {
LABEL_54:
            qdf_trace_msg(
              0x89u,
              2u,
              "%s: %pK: param value %d is wrong",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "dp_get_vdev_param",
              a1,
              a3);
            dp_vdev_unref_delete(a1, v9, 7u, v39, v40, v41, v42, v43, v44, v45, v46, v47);
            return 16;
          }
        }
        else
        {
          raw_spin_unlock(a1 + 18984);
        }
        switch ( a3 )
        {
          case 0u:
            v26 = (unsigned int *)*(unsigned __int8 *)(v9 + 56);
            goto LABEL_43;
          case 1u:
            v26 = (unsigned int *)*(unsigned __int8 *)(v9 + 57);
            goto LABEL_43;
          case 2u:
            v26 = (unsigned int *)*(unsigned __int8 *)(v9 + 48);
            goto LABEL_43;
          case 3u:
            v26 = (unsigned int *)*(unsigned __int8 *)(v9 + 49);
            goto LABEL_43;
          case 4u:
            v26 = (unsigned int *)*(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(v9 + 24) + 8LL) + 18706LL);
            goto LABEL_43;
          case 9u:
            v26 = (unsigned int *)*(unsigned int *)(v9 + 43268);
            *a4 = (_DWORD)v26;
            goto LABEL_44;
          case 0xCu:
            v26 = (unsigned int *)*(unsigned int *)(v9 + 40);
            *a4 = (_DWORD)v26;
            goto LABEL_44;
          case 0x13u:
            v26 = (unsigned int *)*(unsigned __int8 *)(v9 + 58);
            goto LABEL_43;
          case 0x14u:
            v30 = *(unsigned __int8 *)(v9 + 74);
            goto LABEL_42;
          case 0x15u:
            v26 = (unsigned int *)*(unsigned __int8 *)(v9 + 75);
            goto LABEL_43;
          case 0x17u:
            v29 = *(_DWORD **)(a1 + 1456);
            if ( *(v29 - 1) != -1577393019 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, _DWORD *))v29)(a1, v9, a4);
            goto LABEL_44;
          case 0x1Au:
            v26 = (unsigned int *)*(unsigned __int8 *)(v9 + 50);
            goto LABEL_43;
          case 0x1Bu:
            v30 = *(unsigned __int8 *)(v9 + 43248);
LABEL_42:
            v26 = (unsigned int *)((v30 >> 1) & 1);
            goto LABEL_43;
          case 0x1Cu:
            v26 = (unsigned int *)*(unsigned __int8 *)(v9 + 46142);
LABEL_43:
            *(_BYTE *)a4 = (_BYTE)v26;
            goto LABEL_44;
          case 0x1Fu:
            v31 = *(_QWORD *)(v9 + 43520);
            if ( v31 )
            {
              v26 = (unsigned int *)*(unsigned int *)(v31 + 8);
              *a4 = (_DWORD)v26;
              goto LABEL_44;
            }
            v33 = *(unsigned __int8 *)(v9 + 59);
            v34 = "dp_monitor_get_chan_num";
            goto LABEL_50;
          case 0x20u:
            v32 = *(_QWORD *)(v9 + 43520);
            if ( v32 )
            {
              v26 = (unsigned int *)*(unsigned int *)(v32 + 12);
              *a4 = (_DWORD)v26;
            }
            else
            {
              v33 = *(unsigned __int8 *)(v9 + 59);
              v34 = "dp_monitor_get_chan_freq";
LABEL_50:
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: mon vdev is null for vdev %u",
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v34,
                v33);
              *a4 = 0;
            }
LABEL_44:
            dp_vdev_unref_delete(a1, v9, 7u, v26, v18, v19, v20, v21, v22, v23, v24, v25);
            result = 0;
            break;
          default:
            goto LABEL_54;
        }
        return result;
      }
    }
  }
  v27 = *(_QWORD *)(a1 + 18992);
  if ( (v27 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 18992) = v27 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 18984);
  }
  else
  {
    raw_spin_unlock(a1 + 18984);
  }
  return 16;
}
