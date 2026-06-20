void __fastcall gh_hvc_notify_del(__int64 a1, unsigned int a2)
{
  unsigned __int64 v2; // x27
  char *v3; // x20
  __int64 v5; // x21
  unsigned int v6; // w0
  unsigned __int16 v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 > 4 )
    goto LABEL_10;
  v3 = (char *)&gh_hvc_data + 2144 * a2;
  v7 = 0;
  if ( (cancel_work_sync(v3 + 2112) & 1) != 0 )
    gh_hvc_put_work_fn((__int64)(v3 + 2112));
  if ( (unsigned int)ghd_rm_get_vmid(a2, &v7) )
    goto LABEL_10;
  v5 = 2144LL * a2;
  v6 = gh_rm_console_close(v7);
  if ( v6 )
    printk(&unk_965A, "gh_hvc_notify_del", a2, v6);
  if ( (v5 | 0x14uLL) <= 0x29E0 )
  {
    *((_DWORD *)v3 + 5) = 0;
    if ( (v5 | 0x10uLL) <= 0x29E0 )
    {
      *((_DWORD *)v3 + 4) = 0;
LABEL_10:
      _ReadStatusReg(SP_EL0);
      return;
    }
  }
  __break(1u);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v2);
  gh_hvc_notify_console_chars();
}
