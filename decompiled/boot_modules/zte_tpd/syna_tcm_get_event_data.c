__int64 __fastcall syna_tcm_get_event_data(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 (*v4)(void); // x8
  __int64 result; // x0
  __int64 v8; // x2
  __int64 v9; // x2
  unsigned int v10; // w0
  void *v11; // x0
  unsigned int v12; // w19
  void *v13; // x8

  if ( !a1 )
  {
    v11 = &unk_3365A;
LABEL_17:
    printk(v11, "syna_tcm_get_event_data", a3);
    return 4294967055LL;
  }
  if ( !a2 )
  {
    v11 = &unk_38286;
    goto LABEL_17;
  }
  v4 = *(__int64 (**)(void))(a1 + 912);
  if ( *((_DWORD *)v4 - 1) != -519185887 )
    __break(0x8228u);
  result = v4();
  if ( (result & 0x80000000) != 0 )
  {
    v12 = result;
    printk(&unk_3ACBB, "syna_tcm_get_event_data", v8);
    return v12;
  }
  if ( !a3 )
    return result;
  LODWORD(v9) = *a2;
  if ( (unsigned int)(v9 - 255) >= 0xFFFFFF11 )
  {
    if ( !*(_DWORD *)(a1 + 268) )
      return result;
    v10 = syna_tcm_buf_copy_2(a3, a1 + 256);
    v9 = *a2;
    if ( (v10 & 0x80000000) != 0 )
    {
      v13 = &unk_3BA0D;
LABEL_21:
      v12 = v10;
      printk(v13, "syna_tcm_get_event_data", v9);
      return v12;
    }
    result = 0;
  }
  if ( (unsigned int)(v9 - 1) <= 0xE && *(_DWORD *)(a1 + 340) )
  {
    v10 = syna_tcm_buf_copy_2(a3, a1 + 328);
    if ( (v10 & 0x80000000) == 0 )
      return 0;
    v9 = *a2;
    v13 = &unk_3CD23;
    goto LABEL_21;
  }
  return result;
}
