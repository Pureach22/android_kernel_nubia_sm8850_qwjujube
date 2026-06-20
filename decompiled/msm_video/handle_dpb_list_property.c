__int64 __fastcall handle_dpb_list_property(__int64 a1, int *a2, __int64 a3, __int64 a4, __int64 a5)
{
  _QWORD *v5; // x20
  int v6; // w8
  unsigned int v7; // w19
  __int64 v9; // x24
  __int64 v10; // x9
  char *v11; // x26
  unsigned __int64 v12; // x27
  __int64 *v13; // x8
  __int64 i; // x9
  __int64 v15; // x12
  __int64 v16; // x20

  if ( *(_DWORD *)(a1 + 308) != 2 )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    printk(&unk_94054, "err ", a1 + 340, "handle_dpb_list_property", a5);
    return 4294967274LL;
  }
  v5 = (_QWORD *)(a1 + 38436);
  v6 = *a2;
  *(_QWORD *)(a1 + 38484) = 0;
  *(_QWORD *)(a1 + 38492) = 0;
  v7 = v6 - 32;
  *(_QWORD *)(a1 + 38468) = 0;
  *(_QWORD *)(a1 + 38476) = 0;
  *(_QWORD *)(a1 + 38452) = 0;
  *(_QWORD *)(a1 + 38460) = 0;
  *(_QWORD *)(a1 + 38436) = 0;
  *(_QWORD *)(a1 + 38444) = 0;
  if ( (unsigned int)(v6 - 32) >= 0x101 )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v16 = a1;
        printk(&unk_896E5, "err ", a1 + 340, "handle_dpb_list_property", v7);
        a1 = v16;
      }
    }
    msm_vidc_change_state(a1, 5u, (__int64)"handle_dpb_list_property");
    return 4294967274LL;
  }
  v9 = a1;
  memcpy((void *)(a1 + 38436), a2 + 8, (unsigned int)(v6 - 32));
  v10 = v9;
  if ( v7 < 0x10 )
    goto LABEL_18;
  v11 = (char *)v5 + 12;
  v12 = 3;
  while ( 1 )
  {
    if ( !v10 || (msm_vidc_debug & 4) == 0 )
      goto LABEL_13;
    if ( v12 >= 0x40 )
      break;
    printk(&unk_8485B, "low ", v10 + 340, "handle_dpb_list_property", *((unsigned int *)v11 - 3));
    v10 = v9;
LABEL_13:
    v12 += 4LL;
    v11 += 16;
    if ( v12 >= v7 >> 2 )
      goto LABEL_18;
  }
  __break(0x5512u);
LABEL_18:
  v13 = *(__int64 **)(v10 + 2584);
  for ( i = v10 + 2584; v13 != (__int64 *)i; v13 = (__int64 *)*v13 )
  {
    if ( (v13[10] & 0x46) == 2 )
    {
      if ( v7 < 0x10
        || (v15 = v13[7], v15 != *v5)
        && (v7 < 0x20
         || v15 != v5[2]
         && (v7 < 0x30
          || v15 != v5[4]
          && (v7 < 0x40
           || v15 != v5[6]
           && (v7 < 0x50
            || v15 != v5[8]
            && (v7 < 0x60
             || v15 != v5[10]
             && (v7 < 0x70
              || v15 != v5[12]
              && (v7 < 0x80
               || v15 != v5[14]
               && (v7 < 0x90
                || v15 != v5[16]
                && (v7 < 0xA0
                 || v15 != v5[18]
                 && (v7 < 0xB0
                  || v15 != v5[20]
                  && (v7 < 0xC0
                   || v15 != v5[22]
                   && (v7 < 0xD0
                    || v15 != v5[24]
                    && (v7 < 0xE0 || v15 != v5[26] && (v7 < 0xF0 || v15 != v5[28] && (v7 != 256 || v15 != v5[30]))))))))))))))) )
      {
        *((_DWORD *)v13 + 20) |= 0x40u;
      }
    }
  }
  return 0;
}
