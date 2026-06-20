__int64 sub_ED5C()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return md_smem_md_enable();
}
