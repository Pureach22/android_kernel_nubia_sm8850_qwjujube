int __fastcall device_open(inode *inode, file *file)
{
  return single_open(file, device_show, inode->i_private);
}
