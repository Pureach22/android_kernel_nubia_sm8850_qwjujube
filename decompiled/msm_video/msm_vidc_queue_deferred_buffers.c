__int64 __fastcall msm_vidc_queue_deferred_buffers(__int64 ***a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  __int64 ***v5; // x21
  __int64 **v6; // x20

  result = 4294967274LL;
  v4 = 313;
  switch ( a2 )
  {
    case 1u:
      goto LABEL_28;
    case 2u:
      v5 = a1 + 318;
      if ( a1 == (__int64 ***)-2544LL )
        return result;
      goto LABEL_29;
    case 3u:
      v5 = a1 + 328;
      if ( a1 == (__int64 ***)-2624LL )
        return result;
      goto LABEL_29;
    case 4u:
      v5 = a1 + 333;
      if ( a1 == (__int64 ***)-2664LL )
        return result;
      goto LABEL_29;
    case 5u:
      v5 = a1 + 323;
      if ( a1 == (__int64 ***)-2584LL )
        return result;
      goto LABEL_29;
    case 6u:
      return result;
    case 7u:
      v5 = a1 + 338;
      if ( a1 == (__int64 ***)-2704LL )
        return result;
      goto LABEL_29;
    case 8u:
      v5 = a1 + 343;
      if ( a1 == (__int64 ***)-2744LL )
        return result;
      goto LABEL_29;
    case 9u:
      v5 = a1 + 348;
      if ( a1 == (__int64 ***)-2784LL )
        return result;
      goto LABEL_29;
    case 0xAu:
      v5 = a1 + 353;
      if ( a1 == (__int64 ***)-2824LL )
        return result;
      goto LABEL_29;
    case 0xBu:
      v4 = 358;
LABEL_28:
      v5 = &a1[v4];
      if ( &a1[v4] )
        goto LABEL_29;
      return result;
    case 0xCu:
      v5 = a1 + 363;
      if ( a1 == (__int64 ***)-2904LL )
        return result;
      goto LABEL_29;
    case 0xDu:
      v5 = a1 + 368;
      if ( a1 == (__int64 ***)-2944LL )
        return result;
      goto LABEL_29;
    case 0xEu:
      v5 = a1 + 373;
      if ( a1 == (__int64 ***)-2984LL )
        return result;
      goto LABEL_29;
    case 0xFu:
      v5 = a1 + 378;
      if ( a1 == (__int64 ***)-3024LL )
        return result;
LABEL_29:
      msm_vidc_scale_power(a1, 1);
      v6 = *v5;
      break;
    default:
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 4294967274LL;
      printk(&unk_9780D, "err ", (char *)a1 + 340, "msm_vidc_queue_deferred_buffers", a2);
      return 4294967274LL;
  }
  while ( v6 != (__int64 **)v5 )
  {
    if ( ((_BYTE)v6[10] & 1) != 0 )
    {
      result = ((__int64 (__fastcall *)(__int64 ***, __int64 **))msm_vidc_queue_buffer)(a1, v6);
      if ( (_DWORD)result )
        return result;
    }
    v6 = (__int64 **)*v6;
  }
  return 0;
}
