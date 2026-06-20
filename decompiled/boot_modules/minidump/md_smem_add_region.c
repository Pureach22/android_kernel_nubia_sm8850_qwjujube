__int64 __fastcall md_smem_add_region(char *a1)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x24
  const char *v5; // x22

  v2 = raw_spin_lock_irqsave(&mdt_lock);
  v3 = (unsigned int)md_num_regions;
  if ( (unsigned int)md_num_regions >= 0xC9 )
  {
    printk_deferred("Maximum entries reached\n");
    goto LABEL_16;
  }
  if ( qword_1100E8 && *(_DWORD *)(qword_1100E8 + 4) == 1162756684 )
  {
    if ( *(_DWORD *)(qword_1100E8 + 16) < 0xC9u )
    {
      if ( md_num_regions )
      {
        v4 = 0;
        v5 = (const char *)&unk_110100;
        while ( strcmp(v5, a1) )
        {
          ++v4;
          v5 += 48;
          if ( v3 == v4 )
            goto LABEL_11;
        }
        if ( (v4 & 0x80000000) == 0 )
        {
          printk_deferred("Entry name already exist\n");
          LODWORD(v3) = -17;
          goto LABEL_13;
        }
      }
LABEL_11:
      md_add_ss_toc(a1);
      md_add_elf_header(a1);
      LODWORD(v3) = md_num_regions;
      goto LABEL_12;
    }
    printk_deferred("Maximum regions in minidump table reached\n");
LABEL_16:
    LODWORD(v3) = -12;
    goto LABEL_13;
  }
LABEL_12:
  md_num_regions = v3 + 1;
LABEL_13:
  raw_spin_unlock_irqrestore(&mdt_lock, v2);
  return (unsigned int)v3;
}
