__int64 __fastcall ipa_imm_cmd_construct_dma_task_32b_addr(unsigned int a1, unsigned __int8 *a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x20
  __int16 opcode; // w0
  unsigned int v8; // w1
  unsigned int v9; // w1
  __int16 v10; // w8
  int v11; // w9
  int v12; // w10

  if ( (a3 & 1) != 0 )
    v5 = 2336;
  else
    v5 = 3520;
  v6 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, v5, 20);
  if ( v6 )
  {
    opcode = ipahal_imm_cmd_get_opcode(a1);
    v8 = *((_DWORD *)a2 + 2);
    *(_WORD *)(v6 + 2) = opcode + 256;
    *(_WORD *)v6 = 16;
    if ( v8 >= 0x10000 )
    {
      _warn_printk("Size1 is bigger than 16bit width 0x%x\n", v8);
      __break(0x800u);
    }
    v9 = *((_DWORD *)a2 + 4);
    if ( v9 >= 0x10000 )
    {
      _warn_printk("Pkt size is bigger than 16bit width 0x%x\n", v9);
      __break(0x800u);
      v9 = *((_DWORD *)a2 + 4);
    }
    v10 = *(_DWORD *)(v6 + 4);
    v11 = *a2;
    v12 = a2[1];
    *(_WORD *)(v6 + 12) = v9;
    *(_QWORD *)(v6 + 4) = v10 & 0x7FF
                        | (v11 << 11)
                        | (v12 << 12)
                        | (a2[2] << 13)
                        | (a2[3] << 14)
                        | (a2[4] << 15)
                        | (*((_DWORD *)a2 + 2) << 16)
                        | ((unsigned __int64)*((unsigned int *)a2 + 3) << 32);
  }
  return v6;
}
