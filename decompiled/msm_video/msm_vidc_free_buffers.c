__int64 __fastcall msm_vidc_free_buffers(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  _QWORD **v5; // x25
  _QWORD *v6; // x22
  unsigned int v7; // w20
  _QWORD *v8; // x26
  _QWORD *v9; // x8
  _QWORD *v10; // x9

  result = 4294967274LL;
  v4 = 2504;
  switch ( a2 )
  {
    case 1u:
      goto LABEL_28;
    case 2u:
      v5 = (_QWORD **)(a1 + 2544);
      if ( a1 == -2544 )
        return result;
      goto LABEL_29;
    case 3u:
      v5 = (_QWORD **)(a1 + 2624);
      if ( a1 == -2624 )
        return result;
      goto LABEL_29;
    case 4u:
      v5 = (_QWORD **)(a1 + 2664);
      if ( a1 == -2664 )
        return result;
      goto LABEL_29;
    case 5u:
      v5 = (_QWORD **)(a1 + 2584);
      if ( a1 == -2584 )
        return result;
      goto LABEL_29;
    case 6u:
      return result;
    case 7u:
      v5 = (_QWORD **)(a1 + 2704);
      if ( a1 == -2704 )
        return result;
      goto LABEL_29;
    case 8u:
      v5 = (_QWORD **)(a1 + 2744);
      if ( a1 == -2744 )
        return result;
      goto LABEL_29;
    case 9u:
      v5 = (_QWORD **)(a1 + 2784);
      if ( a1 == -2784 )
        return result;
      goto LABEL_29;
    case 0xAu:
      v5 = (_QWORD **)(a1 + 2824);
      if ( a1 == -2824 )
        return result;
      goto LABEL_29;
    case 0xBu:
      v4 = 2864;
LABEL_28:
      v5 = (_QWORD **)(a1 + v4);
      if ( a1 + v4 )
        goto LABEL_29;
      return result;
    case 0xCu:
      v5 = (_QWORD **)(a1 + 2904);
      if ( a1 == -2904 )
        return result;
      goto LABEL_29;
    case 0xDu:
      v5 = (_QWORD **)(a1 + 2944);
      if ( a1 == -2944 )
        return result;
      goto LABEL_29;
    case 0xEu:
      v5 = (_QWORD **)(a1 + 2984);
      if ( a1 == -2984 )
        return result;
      goto LABEL_29;
    case 0xFu:
      v5 = (_QWORD **)(a1 + 3024);
      if ( a1 == -3024 )
        return result;
LABEL_29:
      v6 = *v5;
      if ( *v5 == v5 )
      {
        v7 = 0;
      }
      else
      {
        v7 = 0;
        do
        {
          v8 = (_QWORD *)*v6;
          print_vidc_buffer(4, (__int64)"low ", (__int64)"free buffer", a1, (__int64)v6);
          v9 = (_QWORD *)v6[1];
          if ( (_QWORD *)*v9 == v6 && (v10 = (_QWORD *)*v6, *(_QWORD **)(*v6 + 8LL) == v6) )
          {
            v10[1] = v9;
            *v9 = v10;
          }
          else
          {
            _list_del_entry_valid_or_report(v6);
          }
          *v6 = v6;
          v6[1] = v6;
          msm_vidc_pool_free(a1);
          ++v7;
          v6 = v8;
        }
        while ( v8 != v5 );
      }
      if ( a1 )
      {
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_859F1, "high", a1 + 340, "msm_vidc_free_buffers", v7);
      }
      result = 0;
      break;
    default:
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_9780D, "err ", a1 + 340, "msm_vidc_free_buffers", a2);
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
