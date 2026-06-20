__int64 __fastcall msm_vidc_get_internal_buffers(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  __int64 v5; // x8
  __int64 (*v6)(void); // x9
  int v7; // w0
  __int64 v8; // x8
  _DWORD *v9; // x8
  unsigned int v10; // w21
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x22
  int v14; // w8
  int v15; // w9

  v2 = *(_QWORD *)(a1 + 320);
  if ( !v2 )
    goto LABEL_10;
  v5 = *(_QWORD *)(v2 + 6560);
  if ( !v5 )
  {
    LODWORD(v2) = 0;
    goto LABEL_10;
  }
  v6 = *(__int64 (**)(void))(v5 + 48);
  if ( !v6 )
  {
    LODWORD(v2) = 0;
    v9 = *(_DWORD **)(v5 + 56);
    if ( v9 )
      goto LABEL_15;
LABEL_10:
    v10 = 0;
    goto LABEL_11;
  }
  if ( *((_DWORD *)v6 - 1) != 1958436756 )
    __break(0x8229u);
  v7 = v6();
  v8 = *(_QWORD *)(v2 + 6560);
  LODWORD(v2) = v7;
  if ( !v8 )
    goto LABEL_10;
  v9 = *(_DWORD **)(v8 + 56);
  if ( !v9 )
    goto LABEL_10;
LABEL_15:
  if ( *(v9 - 1) != 1958436756 )
    __break(0x8228u);
  v10 = ((__int64 (__fastcall *)(__int64, _QWORD))v9)(a1, a2);
LABEL_11:
  result = 4294967274LL;
  v12 = 2504;
  switch ( a2 )
  {
    case 1u:
      goto LABEL_42;
    case 2u:
      v13 = a1 + 2544;
      if ( a1 == -2544 )
        return result;
      goto LABEL_43;
    case 3u:
      v13 = a1 + 2624;
      if ( a1 == -2624 )
        return result;
      goto LABEL_43;
    case 4u:
      v13 = a1 + 2664;
      if ( a1 == -2664 )
        return result;
      goto LABEL_43;
    case 5u:
      v13 = a1 + 2584;
      if ( a1 == -2584 )
        return result;
      goto LABEL_43;
    case 6u:
      return result;
    case 7u:
      v13 = a1 + 2704;
      if ( a1 == -2704 )
        return result;
      goto LABEL_43;
    case 8u:
      v13 = a1 + 2744;
      if ( a1 == -2744 )
        return result;
      goto LABEL_43;
    case 9u:
      v13 = a1 + 2784;
      if ( a1 == -2784 )
        return result;
      goto LABEL_43;
    case 0xAu:
      v13 = a1 + 2824;
      if ( a1 == -2824 )
        return result;
      goto LABEL_43;
    case 0xBu:
      v12 = 2864;
LABEL_42:
      v13 = a1 + v12;
      if ( a1 + v12 )
        goto LABEL_43;
      return result;
    case 0xCu:
      v13 = a1 + 2904;
      if ( a1 == -2904 )
        return result;
      goto LABEL_43;
    case 0xDu:
      v13 = a1 + 2944;
      if ( a1 == -2944 )
        return result;
      goto LABEL_43;
    case 0xEu:
      v13 = a1 + 2984;
      if ( a1 == -2984 )
        return result;
      goto LABEL_43;
    case 0xFu:
      v13 = a1 + 3024;
      if ( a1 == -3024 )
        return result;
LABEL_43:
      if ( *(_DWORD *)(a1 + 308) == 2
        && (v14 = *(_DWORD *)(a1 + 312), v14 != 64)
        && ((v15 = *(_DWORD *)(a1 + 18128), (unsigned int)(v15 - 2) <= 0x3E)
         && ((1LL << ((unsigned __int8)v15 - 2)) & 0x4000000000004005LL) != 0
         || v15 == 256
         || *(_QWORD *)(a1 + 20312)
         || v14 == 16 && *(_QWORD *)(a1 + 34088))
        && (is_sub_state(a1, 64) & 1) != 0
        || !(_DWORD)v2
        || (unsigned int)v2 > *(_DWORD *)(v13 + 28)
        || !v10
        || v10 > *(_DWORD *)(v13 + 16) )
      {
        result = 0;
        *(_BYTE *)(v13 + 32) = 0;
        *(_DWORD *)(v13 + 28) = v2;
        *(_DWORD *)(v13 + 16) = v10;
      }
      else
      {
        *(_BYTE *)(v13 + 32) = 1;
        result = 0;
      }
      break;
    default:
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_9780D, "err ", a1 + 340, "msm_vidc_get_internal_buffers", a2);
        result = 4294967274LL;
      }
      else
      {
        result = 4294967274LL;
      }
      break;
  }
  return result;
}
