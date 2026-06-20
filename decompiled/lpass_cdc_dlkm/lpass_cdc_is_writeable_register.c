__int64 __fastcall lpass_cdc_is_writeable_register(__int64 a1, int a2)
{
  __int64 v2; // x20
  unsigned int macro_id; // w0
  __int64 v5; // x9

  v2 = *(_QWORD *)(a1 + 152);
  if ( !v2 )
    return 0;
  macro_id = lpass_cdc_get_macro_id(*(unsigned __int8 *)(v2 + 216), a2);
  if ( (macro_id & 0x80000000) != 0 )
    return 0;
  if ( macro_id >= 5 )
  {
    __break(0x5512u);
    JUMPOUT(0xFFFFFFFFFF179760LL);
  }
  if ( *(_BYTE *)(v2 + macro_id + 217) == 1 && (v5 = (__int64)*(&lpass_cdc_reg_access + macro_id)) != 0 )
    return (*(unsigned __int8 *)(v5
                               + (unsigned __int16)((unsigned __int64)(a2 - (unsigned int)macro_id_base_offset[macro_id]) >> 2)) >> 1)
         & 1;
  else
    return 0;
}
