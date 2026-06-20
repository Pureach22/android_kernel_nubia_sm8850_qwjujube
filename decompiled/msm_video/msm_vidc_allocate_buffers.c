__int64 __fastcall msm_vidc_allocate_buffers(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v5; // x23
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x22
  int v10; // w24
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x4
  __int64 *v14; // x1
  __int64 v15; // x25
  __int64 v16; // x9

  v5 = *(_QWORD *)(a1 + 320);
  result = 4294967274LL;
  v8 = 2504;
  switch ( a2 )
  {
    case 1u:
      goto LABEL_28;
    case 2u:
      v9 = a1 + 2544;
      if ( a1 == -2544 )
        return result;
      goto LABEL_29;
    case 3u:
      v9 = a1 + 2624;
      if ( a1 == -2624 )
        return result;
      goto LABEL_29;
    case 4u:
      v9 = a1 + 2664;
      if ( a1 == -2664 )
        return result;
      goto LABEL_29;
    case 5u:
      v9 = a1 + 2584;
      if ( a1 == -2584 )
        return result;
      goto LABEL_29;
    case 6u:
      return result;
    case 7u:
      v9 = a1 + 2704;
      if ( a1 == -2704 )
        return result;
      goto LABEL_29;
    case 8u:
      v9 = a1 + 2744;
      if ( a1 == -2744 )
        return result;
      goto LABEL_29;
    case 9u:
      v9 = a1 + 2784;
      if ( a1 == -2784 )
        return result;
      goto LABEL_29;
    case 0xAu:
      v9 = a1 + 2824;
      if ( a1 == -2824 )
        return result;
      goto LABEL_29;
    case 0xBu:
      v8 = 2864;
LABEL_28:
      v9 = a1 + v8;
      if ( a1 + v8 )
        goto LABEL_29;
      return result;
    case 0xCu:
      v9 = a1 + 2904;
      if ( a1 == -2904 )
        return result;
      goto LABEL_29;
    case 0xDu:
      v9 = a1 + 2944;
      if ( a1 == -2944 )
        return result;
      goto LABEL_29;
    case 0xEu:
      v9 = a1 + 2984;
      if ( a1 == -2984 )
        return result;
      goto LABEL_29;
    case 0xFu:
      v9 = a1 + 3024;
      if ( a1 == -3024 )
        return result;
LABEL_29:
      if ( !a3 )
        goto LABEL_45;
      v10 = 0;
      break;
    default:
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_9780D, "err ", a1 + 340, "msm_vidc_allocate_buffers", a2);
      return 4294967274LL;
  }
  while ( 1 )
  {
    v12 = msm_vidc_pool_alloc(a1, 0);
    if ( !v12 )
      break;
    *(_QWORD *)v12 = v12;
    *(_QWORD *)(v12 + 8) = v12;
    v14 = *(__int64 **)(v9 + 8);
    if ( v12 == v9 || v14 == (__int64 *)v12 || *v14 != v9 )
    {
      _list_add_valid_or_report(v12);
      v12 = v16;
    }
    else
    {
      *(_QWORD *)(v9 + 8) = v12;
      *(_QWORD *)v12 = v9;
      *(_QWORD *)(v12 + 8) = v14;
      *v14 = v12;
    }
    *(_DWORD *)(v12 + 24) = a2;
    *(_DWORD *)(v12 + 32) = v10;
    if ( v5 )
    {
      v11 = *(_QWORD *)(v5 + 6568);
      if ( v11 )
      {
        v11 = *(_QWORD *)(v11 + 88);
        if ( v11 )
        {
          v15 = v12;
          if ( *(_DWORD *)(v11 - 4) != 1120471144 )
            __break(0x8228u);
          LODWORD(v11) = ((__int64 (__fastcall *)(__int64, _QWORD))v11)(a1, a2);
          v12 = v15;
        }
      }
    }
    else
    {
      LODWORD(v11) = 0;
    }
    ++v10;
    *(_DWORD *)(v12 + 28) = v11;
    if ( a3 == v10 )
    {
LABEL_45:
      if ( a1 )
      {
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_84228, "high", a1 + 340, "msm_vidc_allocate_buffers", a3);
      }
      return 0;
    }
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_9791B, "err ", a1 + 340, "msm_vidc_allocate_buffers", v13);
  return 4294967274LL;
}
