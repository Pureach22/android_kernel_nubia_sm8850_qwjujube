__int64 __fastcall msm_vidc_print_buffer_info(__int64 a1)
{
  __int64 v2; // x11
  __int64 v3; // x26
  __int64 v4; // x27
  __int64 v5; // x28
  __int64 v6; // x20
  __int64 v7; // x21
  __int64 v8; // x12
  __int64 v9; // x13
  __int64 v10; // x25
  __int64 v11; // x14
  __int64 v12; // x15
  __int64 v13; // x16
  __int64 v14; // x17
  __int64 v15; // x24
  __int64 v16; // x23
  void *v17; // x30
  __int64 v18; // x8
  __int64 v19; // x21
  void *v20; // x20
  __int64 v21; // x28
  __int64 v22; // x27
  __int64 v23; // x26
  __int64 v24; // x25
  __int64 v26; // [xsp+10h] [xbp-40h]
  __int64 v27; // [xsp+18h] [xbp-38h]
  __int64 v28; // [xsp+18h] [xbp-38h]
  __int64 v29; // [xsp+20h] [xbp-30h]
  __int64 v30; // [xsp+20h] [xbp-30h]
  __int64 v31; // [xsp+28h] [xbp-28h]
  __int64 v32; // [xsp+28h] [xbp-28h]
  __int64 v33; // [xsp+30h] [xbp-20h]
  __int64 v34; // [xsp+30h] [xbp-20h]
  __int64 v35; // [xsp+38h] [xbp-18h]
  __int64 v36; // [xsp+38h] [xbp-18h]
  __int64 v37; // [xsp+40h] [xbp-10h]
  __int64 v38; // [xsp+40h] [xbp-10h]
  __int64 v39; // [xsp+48h] [xbp-8h]
  __int64 v40; // [xsp+48h] [xbp-8h]

  v2 = a1 + 3024;
  v3 = a1 + 2984;
  v4 = a1 + 2944;
  v5 = a1 + 2904;
  v6 = a1 + 2864;
  v7 = a1 + 2824;
  v8 = a1 + 2784;
  v9 = a1 + 2744;
  v10 = a1 + 2704;
  v11 = a1 + 2584;
  v12 = a1 + 2664;
  v13 = a1 + 2544;
  v14 = a1 + 2624;
  v15 = a1 + 2504;
  v16 = 1;
  v17 = &unk_95656;
  do
  {
    v18 = v15;
    switch ( (int)v16 )
    {
      case 1:
        goto LABEL_30;
      case 2:
        v18 = v13;
        if ( !a1 )
          break;
        goto LABEL_31;
      case 3:
        v18 = v14;
        if ( !a1 )
          break;
        goto LABEL_31;
      case 4:
        v18 = v12;
        if ( !a1 )
          break;
        goto LABEL_31;
      case 5:
        v18 = v11;
        if ( !a1 )
          break;
        goto LABEL_31;
      case 6:
        break;
      case 7:
        v18 = v10;
        if ( !a1 )
          break;
        goto LABEL_31;
      case 8:
        v18 = v9;
        if ( !a1 )
          break;
        goto LABEL_31;
      case 9:
        v18 = v8;
        if ( !a1 )
          break;
        goto LABEL_31;
      case 10:
        v18 = v7;
        if ( !a1 )
          break;
        goto LABEL_31;
      case 11:
        v18 = v6;
LABEL_30:
        if ( a1 )
          goto LABEL_31;
        break;
      case 12:
        v18 = v5;
        if ( !a1 )
          break;
        goto LABEL_31;
      case 13:
        v18 = v4;
        if ( !a1 )
          break;
        goto LABEL_31;
      case 14:
        v18 = v3;
        if ( !a1 )
          break;
        goto LABEL_31;
      case 15:
        v18 = v2;
        if ( !a1 )
          break;
LABEL_31:
        if ( v18 && (msm_vidc_debug & 2) != 0 )
        {
          v34 = v6;
          v36 = v7;
          v19 = v8;
          v20 = v17;
          v30 = v4;
          v32 = v5;
          v21 = v11;
          v22 = v13;
          v26 = v3;
          v28 = v10;
          v23 = v2;
          v24 = v9;
          v38 = v14;
          v40 = v12;
          printk(v17, "high", a1 + 340, buf_type_name_arr[v16], *(unsigned int *)(v18 + 16));
          v17 = v20;
          v14 = v38;
          v12 = v40;
          v13 = v22;
          v11 = v21;
          v9 = v24;
          v8 = v19;
          v2 = v23;
          v3 = v26;
          v10 = v28;
          v4 = v30;
          v5 = v32;
          v6 = v34;
          v7 = v36;
        }
        break;
      default:
        if ( a1 && (msm_vidc_debug & 1) != 0 )
        {
          v33 = v8;
          v35 = v2;
          v29 = v11;
          v31 = v9;
          v39 = v12;
          v27 = v13;
          v37 = v14;
          printk(&unk_9780D, "err ", a1 + 340, "msm_vidc_print_buffer_info", (unsigned int)v16);
          v14 = v37;
          v12 = v39;
          v17 = &unk_95656;
          v13 = v27;
          v11 = v29;
          v8 = v33;
          v2 = v35;
          v9 = v31;
        }
        break;
    }
    ++v16;
  }
  while ( v16 != 16 );
  return 0;
}
