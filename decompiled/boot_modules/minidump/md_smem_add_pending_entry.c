__int64 __fastcall md_smem_add_pending_entry(_QWORD **a1)
{
  __int64 v2; // x20
  _QWORD *v3; // x21
  char *v4; // x22
  __int64 v5; // x24
  __int64 v6; // x8
  _QWORD *v7; // x25
  __int64 v8; // x8
  __int64 v9; // x10
  __int64 v10; // x11
  _QWORD *v11; // x8
  _QWORD *v12; // x9

  v2 = raw_spin_lock_irqsave(&mdt_lock);
  *(_QWORD *)md_ss_toc = 0x454E424C00000001LL;
  v3 = *a1;
  if ( *a1 == a1 )
  {
LABEL_10:
    raw_spin_unlock_irqrestore(&mdt_lock, v2);
    return 0;
  }
  else
  {
    v4 = (char *)&unk_110100;
    v5 = 203;
    while ( --v5 )
    {
      v6 = v3[3];
      v7 = (_QWORD *)*v3;
      *(_QWORD *)v4 = v3[2];
      *((_QWORD *)v4 + 1) = v6;
      v8 = v3[7];
      v9 = v3[4];
      v10 = v3[5];
      *((_QWORD *)v4 + 4) = v3[6];
      *((_QWORD *)v4 + 5) = v8;
      *((_QWORD *)v4 + 2) = v9;
      *((_QWORD *)v4 + 3) = v10;
      md_add_ss_toc(v4);
      md_add_elf_header(v4);
      v11 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v11 == v3 && (v12 = (_QWORD *)*v3, *(_QWORD **)(*v3 + 8LL) == v3) )
      {
        v12[1] = v11;
        *v11 = v12;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      v4 += 48;
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      kfree(v3);
      v3 = v7;
      if ( v7 == a1 )
        goto LABEL_10;
    }
    __break(0x5512u);
    return md_smem_add_header();
  }
}
