__int64 sub_180AF0()
{
  __asm { LDTRB           W22, [X21,#0xF3] }
  return qdf_nbuf_add_frag_debug();
}
